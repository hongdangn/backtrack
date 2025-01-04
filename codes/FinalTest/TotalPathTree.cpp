#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN]; 
long long f[MAXN];               
int subtreeSize[MAXN];       
int n;

void dfs1(int node, int parent) {
    subtreeSize[node] = 1;
    
    for (auto &neighbor : adj[node]) {
        int nextNode = neighbor.first;
        int weight = neighbor.second;
        
        if (nextNode != parent) {
            dfs1(nextNode, node);
            subtreeSize[node] += subtreeSize[nextNode];
            f[1] += (long long)subtreeSize[nextNode] * weight;
        }
    }
}

void dfs2(int node, int parent) {
    for (auto &neighbor : adj[node]) {
        int nextNode = neighbor.first;
        int weight = neighbor.second;
        
        if (nextNode != parent) {
            f[nextNode] = f[node] + (long long)(n - 2 * subtreeSize[nextNode]) * weight;
            dfs2(nextNode, node);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs1(1, -1);

    dfs2(1, -1);

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        result = max(result, f[i]);
    }

    cout << result << endl;
    return 0;
}

