#define MAX_N 5010
#define MAX_M 10010
#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[MAX_N];
int soChang[MAX_N];
int soChangTuXP[MAX_N];
vector<int> adj[MAX_N];
vector<int> next_adj[MAX_N];
int visited[MAX_N];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> 
                min_path;  
                                       
int shortest_path[MAX_N];

void input() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> c[i] >> soChang[i];
    }
    
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int k) {
    memset(visited, 0, sizeof(visited));
    memset(soChangTuXP, 0, sizeof(soChangTuXP));
    
    queue<int> q;
    q.push(k); visited[k] = 1;
    
    while(!q.empty()) {
        int cur = q.front(); 
		q.pop();

        for (int& next: adj[cur]) {
            if(visited[next] == 0) {
                soChangTuXP[next] = soChangTuXP[cur] + 1;
                
                if(soChangTuXP[next] <= soChang[k]) {
                    q.push(next);
                    next_adj[k].push_back(next);
                    visited[next] = 1;
                }
            }
        }
    }
}

void djisktra() {
    memset(visited, 0, sizeof(visited));
    memset(shortest_path, 1, sizeof(shortest_path)); 
    
    shortest_path[1] = 0; visited[1] = 0;
    int cur_node = 1, cur_path;
    min_path.push({0, 1});
    
    while (!min_path.empty()) {
        cur_node = min_path.top().second;
        min_path.pop();

        cur_path = shortest_path[cur_node];
        visited[cur_node] = 1;
        
        if(cur_node == n) break;
        
        for(int& next: next_adj[cur_node]) {
            if (visited[next]) continue;
            
            int weight = c[cur_node];            
            if (shortest_path[next] > cur_path + weight){
                shortest_path[next] = cur_path + weight;
                                                      
                min_path.push({shortest_path[next], next});
            }
        }
    }
}

int main() {
    input();
    for (int i = 1; i <= n; i++) bfs(i);
    
    djisktra();
    cout << shortest_path[n] << endl;
    
    return 0;    
}

