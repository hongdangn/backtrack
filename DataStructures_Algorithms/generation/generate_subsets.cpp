#include <stdio.h>
#include <math.h>

int n, k;
int x[10001];

void print()
{
	printf("(");
	for(int i = 1; i <= k; i++)
	{
		if(i < k)
			printf("%d, ", x[i]);
		else printf("%d", x[i]);
	}
	printf(")\n");
}
int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; i++) x[i] = i;
	print();
	int count = 1;
	while(x[k] != n || x[k] - x[1] != k - 1)
	{
		int key = 0;
		for(int i = k; i >= 1; i--)
		{
			if(x[i] != n - k + i){
				key = i;
				x[i]++;
				break;
			}
		}
		for(int i = key + 1; i <= k; i++)
		{
			x[i] = x[i - 1] + 1;
		}
		count++;
		print();
	}
	printf("%d", count);
}

