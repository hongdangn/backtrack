//C++ 
#include <bits/stdc++.h> 
using namespace std;

int f[20][1000], a[20];
int n, sum;

void input() {
    cin >> n >> sum;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) f[i][j] = -1;
    }
}

int count_num_roots(int k, int s) {
    if (f[k][s] != -1) return f[k][s];
    if (k == 1) {
        if (s && s % a[k] == 0) {
            f[k][s] = 1;
            
        } else f[k][s] = 0;
        
        return f[k][s];
    }
    
    int tmp = s / a[k];
    f[k][s] += 1;
    
    for (int i = 1; i <= tmp; i++) {
        f[k][s] += count_num_roots(k - 1, s - a[k]*i);
    }
    
    return f[k][s];
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    cout << count_num_roots(n, sum);
}

