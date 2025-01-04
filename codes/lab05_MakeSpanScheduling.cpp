#include <bits/stdc++.h>
using namespace std;

vector<int> vorders;
vector<int> edges[10001];
int d[10001];
int n, m, s[10001], visited[10001];
int earliest[10001], res;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
    }
    
    for (int i = 1; i <= n; i++) {
        edges[i].push_back(0);
    }
}

// topology sorting by dfs
void topo_sort(int u) {
    visited[u] = 1;
    
    for (int v: edges[u]) {
        if (!visited[v]) {
            topo_sort(v);
        }
    }
    
    vorders.push_back(u);
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) topo_sort(i);
    }
    
    reverse(vorders.begin(), vorders.end());
    
    for (int u: vorders) {
        for (int v: edges[u]) {
            res = max(res, earliest[u] + d[u]);
            earliest[v] = max(earliest[v], earliest[u] + d[u]);
        }
    }
    
    cout << res;
}

int main() {
    input();
    solve();
}

