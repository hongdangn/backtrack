#include<bits/stdc++.h>
#define ii pair<long long, long long>
#define x first
#define y second
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl '\n'
using namespace std;
const long long oo = 1e16;
char a[1011][1011], st[1000001];
long long n, p, k, m;
ii r[1000001];
vector<ll> v;
ll check(ll x, ll y)
{
}
void solve()
{
    string s;
    cin >> n >> m;
    ll d = 0;
        for(int i = 0; i <= n + 1; i++){
            for(int j = 0; j <= m + 1; j++){
                a[i][j] = '9';
            }
        }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == '1') d++;
        }
    }
    ll mx = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll tmp = 0;
            if(a[i][j] == '0'){
                if(a[i][j-1] == '0') tmp = 1;
                if(a[i][j+1] == '0') tmp = 1;
                if(a[i+1][j] == '0') tmp = 1;
                if(a[i-1][j] == '0') tmp = 1;
                if(a[i-1][j+1] == '0') tmp = 1;
                if(a[i-1][j-1] == '0') tmp = 1;
                if(a[i+1][j-1] == '0') tmp = 1;
                if(a[i+1][j+1] == '0') tmp = 1;

            }
            mx = max(mx, tmp);
        }
    }
    if(d == 0) {cout << "0\n"; return;}
    if(d == n * m) {cout << n * m - 2 << '\n'; return;}
    d = d - (1 - mx);
    cout << d << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t = 1;
    cin >> t;
    while(t--){
        solve();
    }

}
