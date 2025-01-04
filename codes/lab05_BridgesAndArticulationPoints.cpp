#define _CRT_SECURE_NO_DEPRECATE
#define MAX_N 100000
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int soDinh, soCanh;
int num[MAX_N], low[MAX_N];
vector<int> dinhKe[MAX_N];
int curNum = 0, brigdes = 0, arpoint = 0;
int checked[MAX_N];

void input() {
    cin >> soDinh >> soCanh;

    int u, v;
    for (int i = 0; i < soCanh; i++) {
        cin >> u >> v;
        dinhKe[u].push_back(v);
        dinhKe[v].push_back(u);
    }

}

void DFS(int u, int p) {
    low[u] = num[u] = ++curNum;

    int child = 0;
    for (const int& v : dinhKe[u]) {
        //if (u == 40) cout << u << ": " << v << endl;
        if (v == p) continue;
        if (num[v] == -1) {
            child++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            // arpoint

            if (p != u) {
                if (low[v] >= num[u]) {
                    checked[u] = 1;
                }
            }
        }
        else {
            low[u] = min(low[u], num[v]);
        }
        // brigdes
        if (low[v] > num[u]) brigdes++;


    }
    
    if (p == u && child > 1) checked[u] = 1;

}

// build num array, low array
void build_num_and_low_array() {
    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(num));
    memset(checked, 0, sizeof(checked));


    for (int i = 1; i <= soDinh; i++) {
        if (num[i] == -1) DFS(i, i);
    }

    for (int i = 1; i <= soDinh; i++) {
        if (checked[i] == 1) {
            arpoint++;
            //cout << i << endl;
        }
    }

}

int main() {
    //freopen("input.txt", "r", stdin);
    input();
    build_num_and_low_array();

    cout << arpoint << ' ' << brigdes << endl;

    return 0;
}

