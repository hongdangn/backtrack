#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int n;
int start_x, start_y;
int visited[8][8];
int x[100], y[100];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int ans;


void print_sol() {
	for (int i = 0; i < n*n; i++) {
		cout << "(" << x[i] << ", " << y[i] << ") "; 
	}
	cout << "\n";
}

int correct_way(int i, int j) {
	return (!visited[i][j] && (i >= 0 && i < n) && (j >= 0 && j < n));
}

void Try(int k) {
	for (int i = 0; i < 8; i++) {
		if (correct_way(x[k - 1] + dx[i], y[k - 1] + dy[i])) {
			x[k] = x[k - 1] + dx[i]; 
			y[k] = y[k - 1] + dy[i];
			visited[x[k]][y[k]] = 1;
			
			if (k == n*n - 1) {
				ans++;
//				print_sol();
			} else Try(k + 1);
			
			visited[x[k]][y[k]] = 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> start_x >> start_y;
    x[0] = start_x; y[0] = start_y;
    visited[x[0]][y[0]] = 1;
    Try(1);
    cout << ans;
}
