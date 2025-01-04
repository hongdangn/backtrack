//C++ 
#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;

int n, q;

int main() 
{ 
    cin >> n >> q;
    vector<int> a(n);
    
    int res = 0;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {

        int l = i + 1, r = n - 1;
        while (l < r) {
            int tmp = a[i] + a[l] + a[r];
            
            if (tmp > q) {
                r--;
            } else if (tmp < q) {
                l++;
            } else {
                res++;
                l++;
                r--;
            }
        }
    }
    
    cout << res;
}

