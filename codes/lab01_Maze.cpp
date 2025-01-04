//C++
#include <bits/stdc++.h>
using namespace std;

int n, m, r, c;
int a[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int visited[1000][1000];
int d[1000][1000];
queue<pair<int, int>> q;

bool check_out(int row, int col) {
    if (row == n || row == 1 || col == m || col == 1) return true;
    return false;
}

int solve() {
    if (check_out(r + 1, c) || check_out(r, c + 1)) return 0;
    q.push({r, c});
    d[r][c] = 1;

    while (!q.empty()) {
        int check;
        pair<int, int> p = q.front();
        r = p.first, c = p.second;
        visited[r][c] = 1;
        q.pop();

        for (int i = 0; i <= 3; i++) {
            if (!visited[r + dx[i]][c + dy[i]]) {
                if (!check_out(r + dx[i], c + dy[i])) {
                    if (!a[r + dx[i]][c + dy[i]]) {
                        q.push({r + dx[i], c + dy[i]});
                        visited[r + dx[i]][c + dy[i]] = 1;
                        d[r + dx[i]][c + dy[i]] = d[r][c] + 1;
                    }
                } else if(!a[r + dx[i]][c + dy[i]]){
                    return d[r][c] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int res = solve();
    cout << res;
}

