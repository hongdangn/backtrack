#include <stdio.h>
#include <stdlib.h>

int v;
int matrix[100][100];
bool visited[100];
void dfs(int u)
{
	visited[u] = true;
	printf("%d ", u);
	for(int i = 0; i < v; i++){
		if(matrix[u][i] && !visited[i]){
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d", &v);
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	dfs(0);
}

