#include <stdio.h>
#include <math.h>

int m, n;
int a[21][21], k[4][4];
int res[21][21];
int main()
{
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &k[i][j]);
		}
	}
	for(int i = 1; i < m - 1; i++){
		for(int j = 1; j < n - 1; j++){
			for(int x = i - 1; x < i + 2; x++){
				for(int y = j - 1; y < j + 2; y++){
					res[i - 1][j - 1] += k[x - i + 1][y - j + 1]*a[x][y];
				}
			}
		}
	}
	for(int i = 0; i < m - 2; i++){
		for(int j = 0; j < n - 2; j++){
			if(j == n - 3){
				printf("%d", res[i][j]);
				break;
			}
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}
