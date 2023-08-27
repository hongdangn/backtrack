#include<bits/stdc++.h>
using   namespace   std;
long long t, n, k, a[100];
void   solve(long long n, long long k)
{
    if(k <= n)
    {
        for(int i = 1; i <= n; i++){a[i] = -1;}
        if(k > 0){
        a[k] = 100;
        if(k < n){a[k+1] = -200;}}
    }
    else
    {
        solve(n - 1, k - n);
        a[n] = 1000;
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        solve(n, k);
        for(int i = 1; i <= n; i++){cout << a[i] << " ";}
        cout << '\n';
    }
}

