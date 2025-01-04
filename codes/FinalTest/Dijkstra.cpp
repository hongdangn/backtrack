#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_NODES = 100001;
const int INF = INT_MAX;

int n, m, start, finish;
vector<pair<int, int>> adj[MAX_NODES];
int dist[MAX_NODES];
bool visited[MAX_NODES];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    cin >> start >> finish;
    
    fill(dist, dist + n + 1, INF);
    
    dijkstra(start);

    if (dist[finish] == INF) {
        cout << -1;
    } else {
        cout << dist[finish];
    }

    return 0;
}

