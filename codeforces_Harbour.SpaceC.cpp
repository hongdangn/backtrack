#include <bits/stdc++.h>
#include <iostream>
using  namespace  std;

int x;
bool check(int n)
{
    while(n > 1)
    {
        if(n % 2 == 1)
        {
            return 1;
        }
        else n = n/2;
    }
    return 0;
}
int pow(int n)
{
   int count = 0, ans = 1;
   while(n % 2 == 0)
   {
       count++;
       ans *= 2;
       n = n/2;
   }
   return ans;
}
void solve()
{
    cin >> x;
    int count = 0, a[1001], start = 1;
    a[1] = x;
    while(check(x))
    {
        x = x - pow(x);
        count++;
        a[++start] = x;
    }
    while(x != 0)
    {
        x = x/2;
        count++;
        if(x != 0) a[++start] = x;
    }
    cout << count << '\n';
    for(int i = 1; i <= start; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
