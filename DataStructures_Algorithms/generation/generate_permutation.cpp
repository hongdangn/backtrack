#include <stdio.h>
#include <math.h>

int n, x[100], y[100];
void print()
{
	printf("(");
	for(int i = 1; i <= n; i++){
		if(i != n) printf("%d, ", x[i]);
		else printf("%d", x[i]);
	}
	printf(")\n");
}
int check()
{
	for(int i = n; i >= 2; i--){
		if(x[i] > x[i - 1]) return i - 1;
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	int count = 1;
	for(int i = 1; i <= n; i++) x[i] = i;
	print();
	while(check())
	{
		int tmp = check();
		int argmin = 0;
		for(int i = n; i >= tmp + 1; i--){
			if(x[i] > x[tmp]){
				argmin = i;
				break;
			}
		}
		int temp = x[tmp];
		x[tmp] = x[argmin];
		x[argmin] = temp;
		for(int i = tmp + 1; i <= (n + tmp + 1)/2; i++){
			int tmp_value = x[i];
			x[i] = x[n + tmp + 1 - i];
			x[n + tmp + 1 - i] = tmp_value;
		}
		print();
		count++;
	}
	printf("%d", count);
}
