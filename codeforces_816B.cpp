#include <bits/stdc++.h>
using namespace std;
unsigned long long n,k,b,s,a[100001],c[100001];
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
         cin>>n>>k>>b>>s;
         if(k==1)
         {
             if(b!=s){cout<<"-1"<<'\n';}
             else
             {
                 if(n==1)
                   {cout<<b<<'\n';}
                 else {cout<<b<<" ";
                       for(int i=1;i<=n-1;i++)
                        {
                            cout<<0<<" ";
                        }
                        cout<<'\n';
                       }
             }
         }
         else
         {
         long long x=s-k*b;
         if(x<0){cout<<"-1"<<'\n';}
         if(x==0)
         {
             if(n==1){cout<<s<<'\n';}
             else
             {
                 cout<<s<<" ";
                 for(int i=1;i<=n-1;i++)
                 {
                     cout<<0<<" ";
                 }
             }
         }
         if(x>0)
         {
             if(n*(k-1)<x){cout<<"-1"<<'\n';}
             else
             {
                 for(int i=1;i<=n;i++)
                 {
                     if(i==1){c[i]=b;}
                     else{c[i]=0;}
                 }
                 if(x<=k-1)
                 {
                     for(int i=1;i<=n;i++)
                     {
                         if(i==1){a[i]=x;}
                         else a[i]=0;
                     }
                     for(int i=1;i<=n;i++)
                     {
                         cout<<k*c[i]+a[i]<<" ";
                     }
                     cout<<'\n';
                 }
                 else
                 {
                     long long t=x/(k-1),q=x-t*(k-1);
                     for(int i=1;i<=n;i++)
                     {
                         if(i<=t)a[i]=k-1;
                         if(i==t+1)a[i]=q;
                         else a[i]=0;
                     }
                         for(int i=1;i<=n;i++)
                         {
                             cout<<k*c[i]+a[i]<<" ";
                         }
                            cout<<'\n';
                 }
             }
         }
      }
   }
}

