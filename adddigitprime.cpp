#print all the numbers between x and y that if we delete any k digits (k > 0, < the numbe digits of the number) 
#from the right to the left, we all have a prime number

#include<bits/stdc++.h>
using namespace   std;
#define ll long long

ll x, y, a[4], b[4], d[1000001], cnt = 0;
bool prime(ll n)
{
    if(n == 1){return 0;}
    if((n == 2)||(n == 3)){return 1;}
    if(n > 3)
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n%i == 0)
            {
                 return 0;
            }
        }
        return 1;
    }
}
void  check_print(ll n)
{
     if(n > y){return;}
     if((n >= x)&&(n <= y))
     {
        d[++cnt] = n;
     }
     b[1] = 1, b[2] = 3, b[3] = 7, b[4] = 9;
     for(int i = 1; i <= 4; i++)
     {
         if(prime(n*10 + b[i]))
         {
             check_print(n*10 + b[i]);
         }
     }
}
int main()
{
    cin >> x >> y;
    a[1] = 2, a[2] = 3, a[3] = 5, a[4] = 7;
    for(int i = 1; i <= 4; i++)
    {
        check_print(a[i]);
    }
    sort(d + 1, d + cnt + 1);
    cout << cnt << '\n';
    for(int i = 1; i <= cnt; i++)
        cout << d[i] << " ";
}
