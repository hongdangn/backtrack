#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int t, n;

vector<int> find_max(int start, vector<int> &a) {
    vector<int> result;
    if (start == -1) return result;
    
    result.push_back(a[start]);
    
    for (int i = start + 1; i < n; i++) {
        auto it = lower_bound(result.begin(), result.end(), a[i]);
        
        if (it == result.end()) {
            if ((a[i] - result.back()) % 2 != 0) {
                result.push_back(a[i]);
            } 
            
        } else {
            if ((*it - a[i]) % 2 == 0) {
                *it = a[i];
            }
        }
    }
    
    return result;
}

void solve() {
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = -a[i];
        }
        
        int odd = -1, even = -1;
        
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                odd = i;
                break;
            }
        }
        
        vector<int> odd_result = find_max(odd, a);
        vector<int> even_result = find_max(even, a);
        
        cout << max(odd_result.size(), even_result.size()) << "\n";
    }
}

int main()
{
    solve();
    return 0;
}

