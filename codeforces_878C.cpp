#include<bits/stdc++.h>
using   namespace   std;
long long n, k, q, a[1000000], d[1000000];
void  solve()
{
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = 0;
    }
    long long cnt = 0, s = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > q){d[++cnt] = i;}
    }
    if(cnt == 0)
    {
        cout << (n + 1)*(n - k + 1) - n*(n + 1)/2 + (k - 1)*k/2 << '\n';
    }
    else
    {
        long long s = 0, x = 0;
        if(cnt >= 2){
        for(int i = 1; i <= cnt - 1; i++)
        {
            if((d[i + 1] - d[i] >= k + 1))
            {
                  s += (d[i + 1] - d[i] - k)*(d[i + 1] - d[i]) - (d[i + 1] - d[i] - 1)*(d[i + 1] - d[i])/2 + (k - 1)*k/2;
                  x++;
            }
        }}
        if(d[1] - 1 >= k)
        {
            s += d[1]*(d[1] - k) - (d[1] - 1)*d[1]/2 + (k - 1)*k/2;
            x++;
        }
        if(n - d[cnt] >= k)
        {
            s += (n - d[cnt] + 1)*(n - d[cnt] - k + 1) - (n - d[cnt])*(n - d[cnt] + 1)/2 + (k - 1)*k/2;
            x++;
        }
        if(x != 0){cout << s << '\n';}
        else
        {
            cout << 0 << '\n';
        }
    }
}
int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
