#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll alldigits(ll n)
{
    ll s = 0;
    while(n > 0)
    {
        n = n/10;
        s++;
    }
    return s;
}
void solve()
{
    ll A, B, C,k;
    cin >> A >> B >> C >> k;
    if (max(A, B) > C || max(A, B) < C - 1) cout << -1 << '\n';
    else
    {
        ll minA = pow(10, A - 1);
        ll maxA;
        if(A == C){maxA = pow(10, C) - 1 - pow(10, B - 1);}
        if(A < C){maxA = pow(10, A) - 1;}
        ll minB, maxB, result = 0, sett = 0;
        ll num = 0;
        while(minA <= maxA)
        {
            minB = max(pow(10, B - 1), pow(10, C - 1) - minA);
            if(alldigits(minB) > B){minA++;}
            else{
            if (C > max(A, B))
                {maxB = pow(10, B) - 1;}
            else
                {maxB = min(pow(10, B) - 1, pow(10, C) - 1 - minA);}
            result = num;
            num += maxB - minB + 1;
            if(k > num)
            {
                minA++;
            }
            else
            {
                for(int i = minB; i <= maxB; i++)
                {
                    result++;
                    if(result == k)
                    {
                        cout << to_string(minA) + " + " + to_string(i) + " = " + to_string(minA + i) << '\n';
                        sett = 1;
                        break;
                    }
                }
                break;
            }
        }}
        if(sett == 0){cout << -1 << '\n';}
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}
