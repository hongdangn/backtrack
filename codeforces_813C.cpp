#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1000011], d[1000111], l[1000111];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        d[i] = 0;
        l[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        d[a[i]]++;
        l[a[i]] = i;
    }
    long long pos = 0;
    for(int i = n - 1; i >= 1; i--){
        if(a[i] > a[i+1]) {pos = i; break;}
    }
    m = pos;
    long long dem = 0;
    for(int i = 1; i <= pos; i++)
    {
        if(l[a[i]] > m){m = max(m, l[a[i]]);}
    }
    for(int i = 1; i <= m; i++){
        if(d[a[i]]){
            dem++;
            d[a[i]] = 0;
        }
    }
    cout << dem << '\n';

}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
