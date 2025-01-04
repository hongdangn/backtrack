#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int m, n;
vector<int> teach_crs[31], crs_teach_by[31], cfl_to_crs[31];
int res[31], d[11];
int visited[31], result = INT_MAX;
int num_confl;

bool check(int t, int crs) {
    if (visited[crs]) return false;
    
    for (auto other: cfl_to_crs[crs]) {
        if (res[other] == t) {
            return false;
        }
    }
    return true;
}

int get_max_load() {
    for (int i = 1; i <= m; i++) d[i] = 0;
    
    for (int i = 1; i <= n; i++)  {
        d[res[i]]++;
    }
    
    int tmp = INT_MIN;
    for (int i = 1; i <= m; i++) {
        tmp = max(tmp, d[i]);
    }
    
    return tmp;
}

void Try(int crs) {
    for (auto t: teach_crs[crs]) {
        if (check(t, crs)) {
            res[crs] = t;
            visited[crs] = 1;
            
            if (crs == n) {
                int tmp = get_max_load();
                result = min(result, tmp);
            } else Try(crs + 1);
            
            visited[crs] = 0;
            res[crs] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    int k;

    for (int i = 1; i <= m; i++) {
        cin >> k;
        
        for (int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            teach_crs[tmp].push_back(i);
        }
    }
    
    cin >> num_confl;
    int x, y;
    for (int i = 0; i < num_confl; i++) {
        cin >> x >> y;
        cfl_to_crs[x].push_back(y);
        cfl_to_crs[y].push_back(x);
    }
    Try(1);

    cout << result;

    return 0;
}

