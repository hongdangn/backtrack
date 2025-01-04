#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cassert>

using namespace std;

uint64_t randomAddress() {
  char *c;
  c = new char;
  delete c;
  return (uint64_t)c;
}
uint64_t const SEED = chrono::steady_clock::now().time_since_epoch().count() * (randomAddress() | 1);
mt19937 rng(SEED);

template<typename T>
T random(T l, T r) {
  T res = uniform_int_distribution<T>(l, r)(rng);
  return res;
}

#define MASK(i) (1 << (i))
#define GBIT(mask, i) ((mask) & MASK(i))

#define MAX_N 1000
#define MAX_K 100

int n, k;
int d[MAX_N+3][MAX_N+3];

void optimize(vector<int> &route) {
  size_t s = route.size();
  #define COST(x, y) d[route[x]][route[y]]
  for (size_t u = 1; u < s; ++u) {
    for (size_t v = u + 1; v + 1 < s; ++v) {
      if (COST(u-1, u) + COST(v, v+1) > COST(u-1, v) + COST(u, v+1)) {
        for (int i = u, j = v; i < j; ++i, --j) {
          swap(route[i], route[j]);
        }
      }
    }
  }
  #undef COST
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      cin >> d[i][j];
    }
  }
  int res = 0;
  vector<vector<int>> routes(k, {0});
  vector<int> cost(n);
  vector<bool> visited(n);
  for (int i = 0; i < n; ++i) {
    int bestNxt = -1;
    int bestRoute;
    int bestCost;
    for (int nxt = 1; nxt <= n; ++nxt) {
      if (visited[nxt]) {
        continue;
      }
      for (int j = 0; j < k; ++j) {
        int lst = routes[j].back();
        int newCost = cost[j] + d[lst][nxt];
        if (bestNxt == -1 || newCost < bestCost) {
          bestCost = newCost;
          bestNxt = nxt;
          bestRoute = j;
        }
      }
    }
    assert(bestNxt != -1);
    visited[bestNxt] = true;
    cost[bestRoute] += d[routes[bestRoute].back()][bestNxt];
    routes[bestRoute].push_back(bestNxt);
    res = max(res, cost[bestRoute]);
  }
  cout << k << '\n';
  for (auto &route : routes) {
    optimize(route);
    cout << route.size() << '\n';
    for (int &i : route) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("t.inp", "r")) {
    freopen("t.inp", "r", stdin);
  }
  solve();
}
