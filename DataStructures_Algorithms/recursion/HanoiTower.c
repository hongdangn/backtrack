#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n, countChange = 0;
void makeChange(int num, char a, char b, char c){
	if (num == 1) {
		printf("%c -> %c\n", a, c);
		countChange++;
	}
	else{
		makeChange(num - 1, a, c, b);
		makeChange(1, a, b, c);
		makeChange(num - 1, b, a, c);
	}
}
int main()
{
	scanf("%d", &n);
	char a = 'A', b = 'B', c = 'C';
	makeChange(n, a, b, c);
	printf("%d", countChange);
}
