#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool can_match(int task, vector<vector<int>>& adj, vector<int>& match, vector<bool>& visited) {
    if (visited[task]) {
        return false;
    }
    visited[task] = true;
    for (int staff : adj[task]) {
        if (match[staff] == -1 || can_match(match[staff], adj, match, visited)) {
            match[staff] = task;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int staff;
            cin >> staff;
            adj[i].push_back(staff - 1); // Adjust staff index to 0-based
        }
    }

    vector<int> match(m, -1); // -1 indicates no task assigned
    int max_tasks = 0;

    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        if (can_match(i, adj, match, visited)) {
            max_tasks++;
        }
    }

    cout << max_tasks << endl;

    return 0;
}

