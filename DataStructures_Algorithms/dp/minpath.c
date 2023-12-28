#include <stdio.h>
#include <limits.h>

// m: row, n: column 
int i, j, m, n;
int path_matrix[101][101];
int final_col[101];
// min of 3 elements
int minimum(int a, int b, int c)
{
	int min_elements = (a < b)? a: b;
	return (min_elements < c)? min_elements: c;
}

// calculate the minimum path to each cell in a column
int min_cost(int path_matrix[101][101], int m, int n)
{
	int cost_path[101][101];
	for(i = 0; i <= m - 1; i++) cost_path[i][0] = path_matrix[i][0];
	for(j = 1; j <= n - 1; j++){
		for(i = 0; i <= m - 1; i++){
			int fir_path = (i > 0)? cost_path[i - 1][j - 1]: INT_MAX;
			int sec_path = cost_path[i][j - 1];
			int thir_path = (i < m - 1)? cost_path[i + 1][j - 1]: INT_MAX;
			cost_path[i][j] = path_matrix[i][j] + minimum(fir_path, sec_path, thir_path);
		}
	}
	int minimum_cost = INT_MAX;
	for(i = 0; i < m; i++){
		final_col[i] = cost_path[i][n - 1];
		minimum_cost = (final_col[i] < minimum_cost)? final_col[i]: minimum_cost;
	}
	return minimum_cost;
}
int main()
{
	scanf("%d %d", &m, &n);
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &path_matrix[i][j]);
		}
	}
	int minimum_cost = min_cost(path_matrix, m, n);
	printf("%d", minimum_cost);
}

