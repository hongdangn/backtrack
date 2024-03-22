#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int n, a[101], f[101], maxSubSeq;
int savedLoc[101][101], maxI = 0;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	f[0] = 1, maxSubSeq = 1;
	savedLoc[0][0] = a[0];
	for (int i = 1; i < n; i++){
		f[i] = 1;
		int maxJ = -1; 
		
		for (int j = 0; j < i; j++){
			if (a[j] < a[i]){
				if (f[j] + 1 > f[i]) f[i] = f[j] + 1;
				maxJ = j;
			}
		}
		if (f[i] == 1) savedLoc[i][0] = a[i];
		else{
			int count = -1;
			for (int k = 0; k < f[i]; k++){
				if (k < f[i] - 1) savedLoc[i][++count] = savedLoc[maxJ][k];
				else savedLoc[i][++count] = a[i];
			}
		}
		if (f[i] > maxSubSeq){
			maxSubSeq = f[i];
			maxI = i;
		}
	}
	for (int i = 0; i < maxSubSeq; i++){
		printf("%d ", savedLoc[maxI][i]);
	}
	printf("\n%d", maxSubSeq);
}
