#include <stdio.h>
#include <stdbool.h>

int i, n, a[101];
bool check()
{
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1) count++;
        else
        {
            if (count == 0) return false;
            count--;
        }
    }
    if(count == 0) return true;
    else return false;
}
void print_solution(int a[101], int index)
{
	if(index == n){
		if(check()){
		  for(i = 0; i < n; i++) printf("%d", a[i]);
		  printf(" ");
		}
		return;
	}
	int idx;
	for(idx = 1; idx <= 2; idx++){
		if (a[index] == 0 || a[index] == idx)
        {
            int value = a[index];
            a[index] = idx;
            print_solution(a, index + 1);
            a[index] = value; // Backtrack to restore the array
        }
	}
}
int main()
{
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	print_solution(a, 0);
}

