#include<bits/stdc++.h>
using   namespace  std;
long long t, n, a[11], b[11], c[11];
void solve(long long n)
{
    for(int i = 1; i <= 11; i++)
    {
        a[i] = 0; b[i] = 0; c[i] = 0;
    }
    long long t = 0, k = 0;
    while(n > 0)
    {
        a[++k] = n % 10;
        n = n/10;
    }
    for(int i = k; i >= 1; i--)
    {
        if(a[i]%2 == 0)
        {
            cout << a[i]/2; b[i] = a[i]/2;
        }
        else
        {
            c[++t] = a[i];
            if(t%2 != 0)
            {
                cout << (c[t] + 1)/2;
                b[i] = (c[t] - 1)/2;
            }
            else
            {
                cout << (c[t] - 1)/2;
                b[i] = (c[t] + 1)/2;
            }
        }
    }
    cout << " ";
    long long s = 0;
    for(int i = k; i >= 1; i--)
    {
        if(b[i] != 0){s = i;break;}
    }
    if(s == 0){cout << 0;}
    else
    {
        for(int i = s; i >= 1; i--)
        {
            cout << b[i];
        }
    }
    cout << '\n';
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        solve(n);
    }
}
