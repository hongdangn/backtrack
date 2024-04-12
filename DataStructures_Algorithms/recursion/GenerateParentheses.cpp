#include <stdio.h>
#include <stdlib.h>

int n;
char resultGen[101], parentheses[] = "()";

void printResult(){
	for (int i = 0; i < n; i++) {
		printf("%c", resultGen[i]);
	}
	printf("\n");
}

int check(char res[], int end, int inp) {
	int tmp = 0;
	for (int i = 0; i < end; i++) {
		if (res[i] == '(') tmp++;
		else tmp--;
		if (tmp < 0) return 0;
	}
	if (tmp > 0 && end == inp) return 0;
	return 1;
}

void Try(int k) {
	for (int i = 0; i < 2; i++) {
		if (check(resultGen, k, n)) {
			resultGen[k] = parentheses[i];
			
			if (k == n - 1) {
				if (check(resultGen, k + 1, n)) printResult();
			}
			else Try(k + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	Try(0);
//	char x[] = "()()";
//	printf("%d", check(x, 4, 4));
}
