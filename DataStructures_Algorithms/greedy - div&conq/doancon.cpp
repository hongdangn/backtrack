#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, a[101], b[101];
int x[101], checked[101];


void printSolution(int countDoan){
	printf("{");
	for (int i = 0; i < countDoan; i++){
		printf("(%d, %d)", a[x[i]], b[x[i]]);
	}
	printf("}\n");
	printf("%d", countDoan);
}

int findMin(int countDoan){
	int MAX_TMP = 1e9, tmp = -1;
	if (countDoan > 0){
		for (int i = 0; i < n; i++){
			if (!checked[i] && b[i] <= MAX_TMP && a[i] >= b[x[countDoan - 1]]) {
				MAX_TMP = b[i];
				tmp = i;
			}
		}
	}
	else{
		for (int i = 0; i < n; i++){
			if (b[i] < MAX_TMP) {
				MAX_TMP = b[i];
				tmp = i;
			}
		}
	}
	return tmp;
}

void Greedy(){
	int countDoan = 0;
	while(1){
		int tmp = findMin(countDoan);
		if (tmp == -1) break;
		else{
			x[countDoan] = tmp;
			checked[tmp] = 1;
			countDoan++;
		}
	}
	printSolution(countDoan);
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	Greedy();
}
