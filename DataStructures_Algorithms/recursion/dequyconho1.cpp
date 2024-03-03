#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int k, n, m[100][100];

void init()
{
	for (int i = 1; i <= n; i++){
		m[0][i] = 1;
		m[i][i] = 1;
	}
}

int C(int i, int j)
{
	if (i == 0 || i == j) m[i][j] = 1;
	else{
		if (m[i][j] == 0) m[i][j] = C(i - 1, j - 1) + C(i, j - 1);
	}
	return m[i][j];
}
int main()
{
	scanf("%d %d", &k, &n);
	init();
	printf("%d", C(k, n));
}
