#include <stdio.h>

int n, k;
int a[101], b[101];
void print_subset(int length)
{
	int i;
	if(length == k){
		printf("{");
		for(i = 0; i < k; i++){
			if(i < k - 1) printf("%d, ", a[i]);
			else printf("%d", a[i]);
		}
		printf("}\n");
		return;
	}

	for(i = 1; i <= n; i++){
		if(b[i] == 0){
			a[length] = i;
			b[i] = 1;
			print_subset(length + 1);
			b[i] = 0;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	print_subset(0);
}
