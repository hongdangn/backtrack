#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, c[101][101], minCost = 1e9, tmpCost, finalCost = 1e9;
int lowerBound, visited[101], x[101], y[101];
void printSolution(int x[]){
	for (int i = 0; i < n; i++){
		if (i < n - 1) printf("%d ->", x[i]);
		else printf("%d\n", x[i]);
	}
}

void Try(int k){
	for (int i = 1; i < n; i++){
		if (!visited[i]){
			x[k] = i; visited[i] = 1;
			tmpCost += c[x[k - 1]][x[k]];
			if (k == n - 1){
				int tmp = tmpCost + c[x[k]][x[0]];
				if (tmp < finalCost) {
					finalCost = tmp;
					for (int i = 0; i < n; i++) y[i] = x[i];
				}
			}
			else if (tmpCost + minCost * (n - k) < finalCost) Try(k + 1);
			visited[i] = 0;
			tmpCost -= c[x[k - 1]][x[k]];
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &c[i][j]);
			if (c[i][j] < minCost) minCost = c[i][j];
		}
	}
	x[0] = 0;
	Try(1);
	printSolution(y);
}
