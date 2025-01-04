#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001], height[1001];
int res = INT_MIN;

int count_max_rec() {
    int max_rec = INT_MIN;
    stack<int> s;
    int i = 0;
    
    while (i < m) {
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i);
            i++;
        } else {
            int tp = s.top();
            s.pop();
            int tmp_max = height[tp] * (s.empty() ? i : i - s.top() - 1);
            max_rec = max(max_rec, tmp_max);
        }
    }
    
    while (!s.empty()) {
        int tp = s.top(); 
        s.pop();
        
        int tmp_max = height[tp] * (s.empty() ? m : m - s.top() - 1);
        max_rec = max(max_rec, tmp_max);        
    }
    
    return max_rec;
}

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            
            if (a[i][j]) height[j]++;
            else height[j] = 0;
        }
        int tmp_max = count_max_rec();
        res = max(res, tmp_max);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    cout << res;
}

