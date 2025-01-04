#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, t, c;
int res;

int true_get_elements(int dist, vector<int> a) {
    int last_e = a[0], cnt = 1;
    
    for (int i = 1; i < n; i++) {
        if (a[i] - last_e >= dist) {
            cnt++;
            last_e = a[i];
            
            if (cnt == c) return 1;
        }
    }
    
    return 0;
}

int max_dist(vector<int> a) {
    int mindist = 1, maxdist = a[n - 1] - a[0];
    int res = -1;

    while (mindist <= maxdist) {
        int mid = mindist + (maxdist - mindist) / 2;
        
        if (true_get_elements(mid, a)) {
            res = mid;
            mindist = mid + 1;
        } else {
            maxdist = mid - 1;
        }
    }
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while (t--) {
        cin >> n >> c;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        cout << max_dist(a) << "\n";
    }

    return 0;
}

