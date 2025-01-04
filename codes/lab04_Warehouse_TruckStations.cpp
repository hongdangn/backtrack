//C++ 
#include <bits/stdc++.h> 
#include <iostream>
#define MOD 1000000007
using namespace std;

int n, a[1001], t[1001], tme, d;
int f[1001][101];

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> tme >> d;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    
    int res = 0;
    for (int i = t[0]; i <= tme; i++) f[0][i] = a[0];
    res = f[0][tme];
    
    for (int i = 1; i < n; i++) {
        for (int j = t[i]; j <= tme; j++) {
            
            for (int k = i - 1; k >= max(0, i - d); k--) {
                f[i][j] = max(f[i][j], f[k][j - t[i]] + a[i]);
            }
        }
        
        res = max(res, f[i][tme]);
    }
    
    cout << res;
}

