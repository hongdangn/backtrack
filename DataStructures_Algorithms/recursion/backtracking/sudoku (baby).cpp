#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[11][11], countAllWays = 0;
int markRV[11][11], markCV[11][11];
void init()
{
	for (int i = 0; i <= 8; i++){
		for (int j = 1; j <= 9; j++){
			markRV[i][j] = false;
			markCV[i][j] = false;
		}
	}
}
void print()
{
	printf("------------------------\n");
	for (int i = 0; i <= 8; i++){
		for (int j = 0; j <= 8; j++){
			if (j != 8) printf("%d ", x[i][j]);
			else printf("%d\n", x[i][j]);
		}
	}
	printf("------------------------\n");
}
void tryFilling(int r, int c)
{
	for (int i = 1; i <= 9; i++){
		if(!markRV[r][i] && !markCV[c][i]){
			x[r][c] = i;
			markRV[r][i] = true;
			markCV[c][i] = true;
			if (r == 8 && c == 8){
				print();
				countAllWays += 1;
			}
			else{
				if (r == 8) tryFilling(0, c + 1);
				else tryFilling(r + 1, c);
			}
			markRV[r][i] = false;
			markCV[c][i] = false;
		}
	}
}
int main()
{
	init();
	tryFilling(0, 0);
	printf("%d", countAllWays);
}


