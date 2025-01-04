//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, a[100001];
int tmp_max[100001], res = INT_MIN;

int main() 
{ 
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    tmp_max[0] = 1;
    
    for (int i = 1; i < n; i++) {
        tmp_max[i] = 1;
        if (a[i] > a[i - 1]) {
            tmp_max[i] = tmp_max[i - 1] + 1;
        }
        
        res = max(res, tmp_max[i]);
    }
    
    cout << res;
}

