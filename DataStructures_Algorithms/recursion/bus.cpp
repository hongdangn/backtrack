#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int r;
int n, max_psgers;
int x[20], visited[20];
int num_psgers_left;

void print() {
	for (int i = 0; i < 2*n; i++) {
		cout << x[i] << " ";
	}
	cout << "\n";
}

bool check(int i) {
	return (i > n && visited[i - n]) || (i <= n && (num_psgers_left < max_psgers));
}

void Try(int k) {
	for (int i = 1; i <= 2*n; i++) {
		if (!visited[i] && check(i)) {
			x[k] = i;
			visited[i] = 1;
			
			if (k == 2*n - 1) {
				num_psgers_left -= 1;
				print();
				r++;
			} else if ((i > n && visited[i - n])) {
				num_psgers_left -= 1;
				Try(k + 1);
			} else if (i <= n && (num_psgers_left < max_psgers)) {
				num_psgers_left += 1;
				Try(k + 1);
			}
			
			visited[i] = 0;
			if (i > n) num_psgers_left += 1;
			else num_psgers_left -= 1;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> max_psgers;
    Try(0);
    cout << r;
}
