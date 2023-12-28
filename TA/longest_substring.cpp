#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char s[100], t[100];
int dp[100][100];
int max_2(int a, int b)
{
	return (a > b) ? a : b;
}
int max_3(int a, int b, int c)
{
	int m = max_2(a, b);
	return max_2(m, c);
}
int main()
{
	scanf("%s %s", &s, &t);
	int max_count = 0;
	int max_index = 0;
	int m = strlen(s), n = strlen(t);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(s[i] == t[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max_3(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]);
			if(dp[i][j] > max_count){
				max_count = dp[i][j];
			}
		}
	}
	printf("%d", max_count);
}
