#include<bits/stdc++.h>
using    namespace   std;
int d[100000];
void   printdigits(int num, int d[], int cnt)
{
    if(cnt == 5)
    {
        cout << num << " ";
        return;
    }
    d[num] = 1;
    for(int i = 0; i <= 9; i++)
    {
        if(d[i] == 0)
        {
            d[i] = 1;
            printdigits(num*10 + i, d, cnt + 1);
            d[i] = 0; \\backtrack
        }
    }
    d[num] = 0;
}
int main()
{
    for(int i = 1; i <= 9; i++)
    {
        printdigits(i, d, 1);
    }
}
