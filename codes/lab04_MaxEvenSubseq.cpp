#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n, a[1000001];
long long final_even = INT_MIN;
long long max_odd[1000001], max_even[1000001]; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (a[0] % 2 == 0) {
        max_even[0] = a[0];
        max_odd[0] = INT_MIN;
    }
    else {
        max_odd[0] = a[0];
        max_even[0] = INT_MIN;
    }
    
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == 0) {
            max_even[i] = max(a[i], max_even[i - 1] + a[i]);
            
            if (max_odd[i - 1] != INT_MIN) max_odd[i] = a[i] + max_odd[i - 1];
            else max_odd[i] = INT_MIN;
            
        } else {
            max_odd[i] = max(a[i], max_even[i - 1] + a[i]);
            
            if (max_odd[i - 1] != INT_MIN) max_even[i] = a[i] + max_odd[i - 1];
            else max_even[i] = INT_MIN;            
        }
        
        final_even = max(max_even[i], final_even);
    }
    
    if (final_even != INT_MIN) cout << final_even;
    else cout << "NOT_FOUND";
}

