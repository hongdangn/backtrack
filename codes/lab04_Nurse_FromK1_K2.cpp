//C++ 
#include <bits/stdc++.h> 
#include <iostream>
#define MOD 1000000007
using namespace std;

int n, k1, k2;
long long res;
long long f[503][1001];

int count_sols(int num_vars, int sum) {
    if (sum < 0) {
        return 0;
    }
    
    if (sum < k1) {
        f[num_vars][sum] = 0;
        return 0;
    }
    
    if (f[num_vars][sum] != -1) return f[num_vars][sum];
    
    if (num_vars == 1) {
        if (sum >= k1 && sum <= k2) {
            f[num_vars][sum] = 1;
        } else f[num_vars][sum] = 0;
        
        return f[num_vars][sum];
    }
    
    for (int i = k1; i <= k2; i++) {
        if (sum >= i) f[num_vars][sum] = (f[num_vars][sum] + count_sols(num_vars - 1, sum - i)) % MOD;
    }
    
    f[num_vars][sum]++;
    return f[num_vars][sum];
}

long long num_roots(int num_vars) {
    long long roots = 0;
    
    roots = (roots + 2*count_sols(num_vars, n - num_vars)) % MOD;
    roots = (roots + count_sols(num_vars, n - num_vars - 1)) % MOD;
    roots = (roots + count_sols(num_vars, n - num_vars + 1)) % MOD;
    
    return roots;
}

void solve() {
    for (int i = 1; i <= n / 2 + 1; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = -1;
        } 
    }
    
    for (int i = 1; i <= n / 2 + 1; i++) {
        res = (res + num_roots(i)) % MOD;
    }
    
}


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k1 >> k2;
    solve();
    
    cout << res;
}

