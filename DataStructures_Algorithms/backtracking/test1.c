#include <stdio.h>
#include <stdlib.h>

int i, j, k, n;
unsigned long long int c[31][50];
int main()
{
	scanf("%d %d", &k, &n);
	for(j = 0; j <= n; j++){
		c[0][j] = 1;
		c[j][j] = 1;
	}
	for(i = 1; i <= k; i++){
		for(j = 1; j <= n; j++){
			if(j > i){
				c[i][j] = c[i - 1][j - 1] + c[i][j - 1];
			}
		}
	}
	printf("%llu", c[k][n]);
}
