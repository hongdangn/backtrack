#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n, a[1001];
int main()
{
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
	int max_sum = a[0], max_tmp = a[0];
	int start = 0, end = 0;
	int new_start = 0, new_end = 0;
	for(int i = 1; i < n; i++){
		new_end = i;
		if(max_tmp > 0) max_tmp += a[i];
		else{
			max_tmp = a[i];
			new_start = i;
		}
		if(max_tmp > max_sum){
			start = new_start;
			end = new_end;
			max_sum = max_tmp;
		}
	}
	for(int i = start; i <= end; i++) printf("%d ", a[i]);
}
