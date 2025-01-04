//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n;
int visited[100001];
vector<pair<int, int>> adj[100001];
int max_dist, farthest;

void input() {
    cin >> n;
    
    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void dfs(int u, int dist) {
    visited[u] = 1;
    
    if (dist > max_dist) {
        farthest = u;
        max_dist = dist;
    }
    
    for (auto v: adj[u]) {
        if (!visited[v.first]) {
            dfs(v.first, dist + v.second);
        }
    }
}

int main() 
{ 
    input();
    
    dfs(1, 0);
    int tmp_farthest = farthest;
    
    memset(visited, 0, sizeof(visited));
    max_dist = 0;
    dfs(tmp_farthest, 0);
    
    cout << max_dist;
}
