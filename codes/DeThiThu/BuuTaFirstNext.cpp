//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, k, d[1002][1002];
int fir_pos[101], dist[101], next_pos[1002];
int visited[1002], num_ways, all_ways;
int res = INT_MAX;

int final_fir_pos[101], final_next_pos[1002], num_pos[101];

void input() {
    cin >> n >> k;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> d[i][j];
        }
    }
}

int max_dist() {
    int tmp = INT_MIN;
    
    for (int i = 1; i <= k; i++) {
        tmp = max(tmp, dist[i]);
    }
    
    return tmp;
}

bool check(int pos) {
    if (pos == 0) return true;
    if (visited[pos]) return false;
    
    return true;
}

void get_final_sol() {
    for (int i = 1; i <= k; i++) {
        num_pos[i] = 0;
        int fir = fir_pos[i];
        final_fir_pos[i] = fir;
        
        if (!fir) {
            final_next_pos[fir] = 0;
        }
        
        while (fir) {
            num_pos[i]++;
            final_next_pos[fir] = next_pos[fir];
            fir = next_pos[fir];
            
            if (!fir) {
                final_next_pos[fir] = 0;
            }
        }
    }
}

void print_final_sol() {
    cout << k << "\n";
    for (int i = 1; i <= k; i++) {
        int fir = final_fir_pos[i];
        
        cout << num_pos[i] + 1 << "\n" << 0 << " ";
        while (fir) {
            cout << fir << " ";
            fir = final_next_pos[fir];
        }
        cout << "\n";
    }
}

void try_another(int t, int pos) {
    if (pos == 0) {
        if (t < k) try_another(t + 1, fir_pos[t + 1]);
        
        return;
    }
    
    for (int i = 0; i <= n; i++) {
        if (check(i)) {
            visited[i] = 1;
            next_pos[pos] = i;
            all_ways++;
            
            if (!i) {
                if (t == k) {
                    if (all_ways == num_ways + n) {
                        int tmp = max_dist();
                        if (tmp < res) {
                            res = min(tmp, res);
                            get_final_sol();
                        }
                    }
                }
                else try_another(t + 1, fir_pos[t + 1]);
            } else {
                dist[t] += d[pos][i];
                try_another(t, i);    
            }
            
            visited[i] = 0;
            all_ways--;
            
            if (i) dist[t] -= d[pos][i];
        }
    }
}

void try_fir(int ord) {
    int start = 0;
    if (ord >= 2 && fir_pos[ord - 1]) {
        start = fir_pos[ord - 1] + 1;
    } 
    
    for (int i = start; i <= n; i++) {
        if (check(i)) {
            fir_pos[ord] = i;
            visited[i] = 1;
            dist[ord] += d[0][i];
            if (i) {
                num_ways++;
            }
            
            if (ord == k) {
                all_ways = num_ways;
                try_another(1, fir_pos[1]);
            } else try_fir(ord + 1);
            
            visited[i] = 0;
            dist[ord] -= d[0][i];
            if (i) {
                num_ways--;
            }
        }
    }
}

void solve() {
    try_fir(1);
    print_final_sol();
}

int main() 
{ 
    input();
    solve();
}

