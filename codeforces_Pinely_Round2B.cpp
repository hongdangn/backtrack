// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int n, p[100001], a[100001];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        a[p[i]] = i;
    }
    // a[i] is the location of i in the array p.
    
    int ans = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        if(a[i] > a[i + 1]) ans += 1;
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
