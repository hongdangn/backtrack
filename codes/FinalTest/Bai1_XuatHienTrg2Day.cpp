#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, m;
int a[101], b[101];

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        unordered_map<long long, int> mp;
        int res = 0;
        
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> b[j];
            if (mp[b[j]]) res++;
        }
        
        cout << res << "\n";
    }

    return 0;
}
