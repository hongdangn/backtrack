#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[201], b[201];
int dp[201][201];
int main()
{
	scanf("%s %s", &a, &b);
	int m = strlen(a), n = strlen(b);
	int max_index_1 = 0, max_index_2 = 0;
	int max_count = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = 0;
			if(dp[i][j] > max_count){
				max_count = dp[i][j];
				max_index_1 = i;
			}
		}
	}
//	for(int i = max_count - 1; i >= 0; i--){
//		printf("%c", a[max_index_1 - i]);
//	}
	printf("%d", max_count);
	return 0;
}
