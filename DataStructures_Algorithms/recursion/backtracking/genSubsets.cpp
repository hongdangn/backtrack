#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int t, n, x[1001], countSubsets = 0;
int y[1001];
void init(){
	for(int i = 1; i <= n; i++) x[i] = false;
}
void print()
{
	printf("{");
	for (int i = 0; i <= t - 1; i++) {
		if (i != t - 1) printf("%d, ", y[i]);
		else printf("%d", y[i]);
	}
	printf ("}\n");
}
void Try(int k)
{
	for (int i = 1; i <= n; i++){
		if(!x[i]){
			y[k] = i;
			x[i] = true;
			if (k == t - 1){
				print();
				countSubsets += 1;
			}
			else Try(k + 1);
			x[i] = false;
		}
	}
}
int main()
{
	scanf("%d %d", &t, &n);
	init();
	Try(0);
	printf("%d", countSubsets);
}
