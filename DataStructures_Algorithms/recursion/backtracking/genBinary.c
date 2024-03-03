#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n, x[1001], countString = 0;
void Try(int k)
{
	int i, j;
	for (i = 0; i <= 1; i++){
		x[k] = i;
		if (k == n - 1) {
			for (j = 0; j <= n - 1; j++) printf("%d", x[j]);
			countString++;
			printf("\n");
		}
		else {
			printf("de quy tai k = %d\n", k);
			Try(k + 1);
		}
	}
}
int main()
{
	scanf("%d", &n);
	Try(0);
	printf("%d", countString);
}
