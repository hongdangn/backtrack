#include <bits/stdc++.h>
using namespace std;

int t, ll, height, width;
int n;


void solve() {
    cin >> t;
    
    while (t--) {
        cin >> ll >> width >> height;
        cin >> n;
        
        int lx, wy, hz;
        set<tuple<int, int, int>> s;

        for (int i = 1; i <= n; i++) {
            cin >> lx >> wy >> hz;
            s.insert({lx, wy, hz});
        }
        
        vector< vector<vector<int>> > waste(ll + 1, vector<vector<int>>(width + 1, vector<int>(height + 1)));
        
        for (int i = 1; i <= ll; i++) {
            for (int j = 1; j <= width; j++) {
                for (int k = 1; k <= height; k++) {
                    int tp = i * j * k;
                    
                    if (s.count({i, j, k}) ||
                        s.count({i, k, j}) || 
                        s.count({j, i, k}) ||
                        s.count({j, k, i}) ||
                        s.count({k, i, j}) ||
                        s.count({k, j, i})) {
                    
                        waste[i][j][k] = 0;
                        continue;
                    }
                    
                    for (int x = 1; x < i; x++) {
                        tp = min(tp, waste[x][j][k] + waste[i - x][j][k]);
                    }
                    
                    for (int y = 1; y < j; y++) {
                        tp = min(tp, waste[i][y][k] + waste[i][j - y][k]);
                    }
                    
                    for (int z = 1; z < k; z++) {
                        tp = min(tp, waste[i][j][z] + waste[i][j][k - z]);
                    }
                    
                    waste[i][j][k] = tp;
                }
            }
        }
        
        cout << waste[ll][width][height] << "\n";
    }
}

int main()
{
    solve();

    return 0;
}

