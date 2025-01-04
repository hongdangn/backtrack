//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, l1, l2;
long long a[1000001], cur_max[1000001];

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> l1 >> l2;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long res = a[0];
    cur_max[0] = a[0];
    
    for (int i = 1; i < n; i++) {
        cur_max[i] = a[i];
        
        for (int j = i - l1; j >= max(0, i - l2); j--) {
            cur_max[i] = max(cur_max[i], cur_max[j] + a[i]);
        }
        
        res = max(res, cur_max[i]);
    }
    
    cout << res;
}

