//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, a[21];
int x[21];
int res = INT_MAX;

int count_sum(int all_sum) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += x[i] * a[i];
    }
    
    return abs(2*s - all_sum);
}

void Try(int k, int all_sum) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        
        if (k == n - 1) {
            int tmp = count_sum(all_sum);
            res = min(res, tmp);
            
        } else Try(k + 1, all_sum);
    }
}

int main() 
{ 
    cin >> n;
    int all_sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all_sum += a[i];
    }
    
    Try(0, all_sum);
    cout << res;
}

