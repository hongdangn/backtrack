#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int x[7]; // x[0]=I, x[1]=C, x[2]=T, x[3]=H, x[4]=U, x[5]=S, x[6]=K
int used[10];
int n, ans = 0;

bool true_sol() {
	int res = x[0]*100 + x[1]*10 + x[2] - x[6]*100 - 62
	                   + x[3]*1000 + x[4]*100 + x[5]*10 + x[2];

	if (res == n) return true;
	return false;
} 

void Try(int k) {
	for (int i = 1; i <= 9; i++) {
		if (!used[i]) {
			x[k] = i;
			used[i] = 1;
			
			if (k == 6) {
				if (true_sol()) ans += 1;
			} else Try(k + 1);
			
			used[i] = 0;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    Try(0);
    cout << ans;
}
