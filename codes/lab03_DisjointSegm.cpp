//C++
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define MAX_VAL 1000001
using namespace std;

int n;
pair<int, int> p[100000];
int res, last = 0;

bool compare_sec(pair<int, int> &x,
                 pair<int, int> &y) {
    return (x.second < y.second);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, compare_sec);
    res = 1;

    for (int i = 1; i < n; i++) {
        if (p[i].first > p[last].second) {
            last = i;
            res++;
        }
    }
    cout << res;
}

