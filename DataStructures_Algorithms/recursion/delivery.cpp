#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;
int loc[10], visited[10];

void print() {
	for (int i = 0; i < n; i++) {
		cout << loc[i] << " ";
	}
	cout << "\n";
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			loc[k] = i;
			visited[i] = 1;
			if (k == n - 1) print();
			else Try(k + 1);
			visited[i] = 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    Try(0);
}
