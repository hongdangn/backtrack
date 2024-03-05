#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, c[101][101];
int x[101], k, finalCost;
int visited[101];

void printSolution(){
	for (int i = 0; i < n; i++){
		if (i < n - 1) printf("%d ->", x[i]);
		else printf("%d\n", x[i]);
	}
}
void Greedy(){
	int nextCity, minCost = 1e9;
	while (k != n - 1){
		for (int i = 1; i < n; i++){
			if (!visited[i]) {
				if (c[x[k - 1]][i] < minCost) {
					minCost = c[x[k - 1]][i];
					x[k] = i;
				}
			}
		}
		visited[x[k]] = 1;
		k++;
	}
	printSolution();	
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &c[i][j]);
		}
	}
	x[0] = 0;
	Greedy();
}
