#include<bits/stdc++.h>
using   namespace   std;
long long n, a[10001];
long long  search_find(long long k)
{
    long long i = 2;
    while(k > 1)
    {
         if(k % i == 0)
         {
             a[i]++;
             k = k/i;
         }
         else {i++;}
    }
    long long s = 0;
    for(int j = 2; j <= n; j++)
    {
        s += a[j];
        a[j] = 0;
    }
    return s;
}
long long Result(long long x)
{
    if(x == 2){return 1;}
    else
    {
        return search_find(x) + Result(x - 1);
    }
}
int main()
{
    cin >> n;
    cout << Result(n);
}
