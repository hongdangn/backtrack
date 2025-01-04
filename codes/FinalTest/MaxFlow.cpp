#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int parent[10001];
vector<int> adj[10001];
int n, m, u, v, c, s, t;
int cap[10001][10001];
int visited[10001];

bool bfs() {
	for (int i = 1; i <= n; i++) visited[i] = 0;
	queue<int> q;
	q.push(s); visited[s] = 1;
	
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		
		if (top == t) return true;
		
		for (int i = 0; i < adj[top].size(); i++) {
			int u = adj[top][i];
			if (!visited[u] && cap[top][u] > 0) {
				visited[u] = 1;
				q.push(u);
				parent[u] = top;
			}
		}		
	}
	
	return 0;
}

int ford_fulkerson() {
	int max_flow = 0;
	
	while (bfs()) { // while we can find the increasing path
		int min_edge = INT_MAX;
		int u = parent[t], cur = t;
		if (min_edge > cap[u][cur]) min_edge = cap[u][cur];
		
		while (u != s) {
			int tmp = u;
			u = parent[u]; cur = tmp;
			if (min_edge > cap[u][cur]) min_edge = cap[u][cur];
		}
		
		max_flow += min_edge;
		
		u = parent[t], cur = t; cap[u][cur] -= min_edge;
		
		while (u != s) {
			int tmp = u;
			u = parent[u]; cur = tmp;
			cap[u][cur] -= min_edge;
		}
		
	}
	return max_flow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		adj[u].push_back(v);
		cap[u][v] = c;
	}
	
	cout << ford_fulkerson();
	return 0;
}

