#include<bits/stdc++.h>
using   namespace   std;
long long n,a[100001];
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long k=998244353;
        long long x=1,y=1;
        sort(a+1,a+n+1);
        if(a[n]-a[n-1]>=2){cout<<"0"<<endl;}
        if(a[n]==a[n-1]+1)
        {
            long long d=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==a[n-1]){d++;}
            }
            for(int i=1;i<=n;i++)
            {
                x=x*i;
            }
            cout<<(x*d/(d+1))%k;
            cout<<endl;
        }
        if(a[n]==a[n-1])
        {
            for(int i=1;i<=n;i++)
            {
                x=(x%k)*i;
            }
            cout<<x<<endl;
        }
    }
}
