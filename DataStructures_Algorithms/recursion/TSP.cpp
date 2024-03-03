#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, c[101][101], visited[101], tmpCost, finalCost = 10000001;
int x[101], y[101];

void getFinalWay(int x[]){
	for (int i = 0; i < n; i++){
		if (i < n - 1) printf("%d ->", x[i]);
		else printf("%d", x[i]);
	}
	printf("\n");
}

void Try(int k){
	for (int i = 1; i < n; i++){
		if (!visited[i]){
			x[k] = i;
			visited[i] = 1;
			tmpCost += c[x[k - 1]][x[k]];
			if (k == n - 1){
				int tmp = tmpCost + c[x[k]][x[0]];
				if (tmp < finalCost){
					for (int i = 0; i < n; i++) y[i] = x[i];
					finalCost = tmp;
				}
			}
			else Try(k + 1);
			tmpCost -= c[x[k - 1]][x[k]];
			visited[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	x[0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &c[i][j]);
		}
	}
	Try(1);
	getFinalWay(y);
	printf("%d", finalCost);
}
