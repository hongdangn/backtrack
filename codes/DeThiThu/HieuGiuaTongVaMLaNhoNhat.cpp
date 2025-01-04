//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, a[21];
int m;
int x[21], res = INT_MAX;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
}

int count_sum() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * x[i];
    }
    return sum;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        
        if (k == n - 1) {
            int tmp = count_sum();
            if (tmp && tmp <= m) res = min(res, m - tmp);
        } else Try(k + 1);
    }
}

void solve() {
    Try(0);
}

int main() 
{ 
    input();
    solve();
    
    cout << res;
}

