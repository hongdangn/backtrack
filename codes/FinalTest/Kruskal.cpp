#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define MAX_N 100001
using namespace std;

int n, m;
int x, y, w;
int parent[MAX_N], r[MAX_N];
vector< vector<int> > edge_list;
int res;

void makeset() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		r[i] = 1;
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	
	return find(parent[x]);
}

void unite(int x, int y) {
	int root_x = find(x);
	int root_y = find(y);
	
	if (r[root_x] <= r[root_y]) {
		parent[root_x] = root_y;
		r[root_y]++;
		
	} else {
		parent[root_y] = root_x;
		r[root_x]++;
	}
}

int main() {
	cin >> n >> m;
	makeset();
	
	vector< vector<int> > edge_list;
	
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		vector<int> edge(3);
		edge[0] = w; edge[1] = x; edge[2] = y;
		
		edge_list.push_back(edge);
	}
	
	sort(edge_list.begin(), edge_list.end());
	
	for (int i = 0; i < m; i++) {
		vector<int> edge = edge_list[i];
		int w = edge[0];
		int u = edge[1], v = edge[2];
		
		if (find(u) != find(v)) {
			res += w;
			unite(u, v);
		}
	}
	cout << res;
}

