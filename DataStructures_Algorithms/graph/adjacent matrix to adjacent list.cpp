
#include <stdio.h>
#include <stdlib.h>

int v;
int matrix[100][100];
int main()
{
	scanf("%d", &v);
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	for(int i = 0; i < v; i++){
		printf("%d -> ", i);
		int last = -1;
		for(int j = v - 1; j >= 0; j--){
			if(matrix[i][j] != 0){
				last = j;
				break;
			}
		}
		for(int j = 0; j <= last; j++){
			if(matrix[i][j] != 0){
				if(j < last) printf("%d -> ", j);
				else printf("%d", j);
			}
		}
		if(last == -1) printf("NULL");
		printf("\n");
	}
}
