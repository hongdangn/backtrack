//C++ 
#include <bits/stdc++.h> 
using namespace std;

int height, width;
int n;
int h[11], w[11], shape[11];
int grid[11][11], res;

void input() {
    cin >> height >> width;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
    }
}

bool check(int r, int c, int w, int h) {
    
    for (int i = r; i < r + w; i++) {
        for (int j = c; j < c + h; j++) {
            if (grid[i][j]) return false;
        }
    }
    
    return true;
}

void place(int r, int c, int w, int h, int val) {
    
    for (int i = r; i < r + w; i++) {
        for (int j = c; j < c + h; j++) {
            grid[i][j] = val;
        }
    }
    
}

void Try(int k) {
    int hk, wk;
    
    for (int i = 0; i <= 1; i++) {
        shape[k] = i;
        
        if (i) {
            hk = h[k], wk = w[k];
        } else {
            hk = w[k], wk = h[k];
        }
        
        for (int i = 1; i <= width - wk + 1; i++) {
            for (int j = 1; j <= height - hk + 1; j++) {
                if (check(i, j, wk, hk)) {
                    place(i, j, wk, hk, 1);
                    
                    if (k == n) {
                        res = 1;
                        return;
                    } else Try(k + 1);
                    
                    place(i, j, wk, hk, 0);
                }
            }
        }
    } 
}

void solve() {
    Try(1);
    cout << res;
}

int main() 
{ 
    input();
    solve();
}

