#include <stdio.h>
#include <math.h>

int n, bit[30];
int main()
{
	scanf("%d", &n);
	int count_zeros = n, count = 1;
	for(int i = 0; i < n; i++)
		printf("%d", bit[i]);
	printf("\n");
	while(count_zeros != 0)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			if(bit[i] == 0){
				bit[i] = 1;
				count_zeros -= 1;
				break;
			}
			else{
				bit[i] = 0;
				count_zeros += 1;
			}
		}
		for(int i = 0; i < n; i++)
			printf("%d", bit[i]);
		printf("\n");
		count++;
	}
	printf("%d", count);
}

