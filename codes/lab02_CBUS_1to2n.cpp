#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define MAX_VAL 100000009
using namespace std;

int n, m;
int d[30][30];
int x[30];
int visited[30];
int res = MAX_VAL;
int num_psg, tmp_route;

int check(int i) {
	if (visited[i]) return 0;
	if (i <= n) {
		if (num_psg + 1 > m) return 0;
	} else {
		if (!visited[i - n]) return 0;
	}
	return 1;
}

void Try(int k, int mmin) {
	for (int i = 1; i <= 2*n; i++) {
		if (check(i)) {
			x[k] = i;
			visited[i] = 1;
			
			if (i <= n) num_psg++;
			else num_psg--;
			
			tmp_route += d[x[k - 1]][x[k]];
			
			if (k == 2*n) {
				if (tmp_route + d[x[k]][0] < res) res = tmp_route + d[x[k]][0];
				
			} else if (tmp_route + mmin*(2*n + 1 - k) < res) Try(k + 1, mmin);
			
			if (i > n) num_psg++;
			else num_psg--;
			
			tmp_route -= d[x[k - 1]][x[k]];
			visited[i] = 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    int mmin = MAX_VAL;
    
    for (int i = 0; i <= 2*n; i++) {
    	for (int j = 0; j <= 2*n; j++) {
    		cin >> d[i][j];
    		if (d[i][j] && d[i][j] < mmin) mmin = d[i][j]; 
		}
	}
	
	Try(1, mmin);
	cout << res;
}

