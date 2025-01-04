#define MAX_N 1000000
#include <bits/stdc++.h>
using namespace std;

int soDinh, soCanh;
vector<int> dinhKe[MAX_N];
int curNum = 0;
int num[MAX_N], low[MAX_N];
bool available[MAX_N];
stack<int> stk;
int soThanhPhanLTM = 0;

void input() {
    cin >> soDinh >> soCanh;
    
    int u, v;
    for (int i = 0; i < soCanh; i++) {
        cin >> u >> v;
        dinhKe[u].push_back(v);
    }
}

void DFS(int u) {
    stk.push(u);
    num[u] = low[u] = ++curNum;
    for (const int &v : dinhKe[u]) {

        if (num[v] == -1) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if (available[v]) {
            low[u] = min(low[u], num[v]);
        }
    }
    
    // neu low[u] = num[u] thi day la dinh cua mot thanh phan lien thong manh
    if (low[u] == num[u]) {
        soThanhPhanLTM++;
        while (true) {
            int v = stk.top(); stk.pop();
            available[v] = false;
            if (v == u) break; 
        }
    }
}

void solve() {
    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(num));
    for (int i = 1; i <= soDinh; i++) available[i] = true;
    
    
    for (int i = 1; i <= soDinh; i++) {
        if (available[i]) DFS(i);
    }
    
    cout << soThanhPhanLTM << endl;
}

int main() {
    input();
    solve();
    
    return 0;
}

