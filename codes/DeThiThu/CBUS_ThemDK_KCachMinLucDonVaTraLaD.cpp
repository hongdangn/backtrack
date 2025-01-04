//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, k, d, c[24][24];
int p[24], visited[24];
int dist_pick[12], num_pick;
int res = INT_MAX, tmp_res;
int min_dist = INT_MAX;

void input() {
    cin >> n >> k >> d;
    
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if (c[i][j]) min_dist = min(min_dist, c[i][j]);
        }
    }
}

bool check(int t, int pos) {
    if (visited[pos]) return false;
    
    if (pos <= n) {
        if (num_pick == k) {
            return false;
        }
        return true;
    }
    
    if (!visited[pos - n]) return false;
    if (dist_pick[pos - n] + c[p[t - 1]][pos] < d) return false;
    
    return true;
} 

void Try(int t) {
    for (int i = 1; i <= 2*n; i++) {
        if (check(t, i)) {
            int tmp = c[p[t - 1]][i];
            
            for (int j = 1; j <= n; j++) {
                if (visited[j]) dist_pick[j] += tmp;
            }
            visited[i] = 1;
            tmp_res += tmp; p[t] = i;
            if (i <= n) num_pick++;
            else num_pick--;
            
            if (t == 2*n) {
                res = min(res, tmp_res + c[i][0]);
                
            } else if (tmp_res + (2*n + 1 - t) * min_dist < res) Try(t + 1);
            
            visited[i] = 0;
            tmp_res -= tmp;
            
            if (i <= n) num_pick--;
            else num_pick++;
            
            for (int j = 1; j <= n; j++) {
                if (visited[j]) dist_pick[j] -= tmp;
            }
            
        }
    }
}

void solve() {
    Try(1);
    if (res != INT_MAX) cout << res;
    else cout << -1;
}

int main() 
{ 
    input();
    solve();
}

