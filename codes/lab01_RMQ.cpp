#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, a[1000001];
int m, x[1000001], y[1000001];
int min_arr[1000001][20];
int res;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		min_arr[i][0] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++) cin >> x[i] >> y[i];
	
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			if (a[min_arr[i][j - 1]] < a[min_arr[i + (1 << (j - 1))][j - 1]]) {
				min_arr[i][j] = min_arr[i][j - 1];
			} else {
				min_arr[i][j] = min_arr[i + (1 << (j - 1))][j - 1];	
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		int range = y[i] - x[i] + 1;
		int k = (int)log2(range);
		
		res += min(a[min_arr[x[i]][k]], a[min_arr[y[i] - (1 << k) + 1][k]]);
	}
	
	cout << res;
}

