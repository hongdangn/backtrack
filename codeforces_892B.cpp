#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n, t, m[25001];
long long a[50001];
long long b[25001], c[25001];
void solve()
{
	long long k = 0, l = 0, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m[i];
		for(int j = 1; j <= m[i]; j++)
		{
			cin >> a[j];
		}
		sort(a + 1, a + m[i] + 1);
		b[++k] = a[1];
		if(m[i] > 1) c[++l] = a[2];
		else c[++l] = 0;
		sum += c[l];
	}
	int min_1 = b[1], min_2 = c[1];
	for(int i = 1; i <= n; i++)
	{
		if(b[i] < min_1)
		{
			min_1 = b[i];
		}
		if(c[i] < min_2)
		{
			min_2 = c[i];
		}
	}
	cout << sum + min_1 - min_2<< '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
