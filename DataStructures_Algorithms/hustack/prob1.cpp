#include <stdio.h>
#include <string.h>

int n, arr[101];
int parenthesis[] = {1, 2};

void printResult() {
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	printf(" ");
}

int checkArray(int end) {
	int tmp = 0;
	for (int i = 0; i < end; i++) {
		if (arr[i] == 1) tmp++;
		else tmp--;
		if (tmp < 0) return 0;
	}
	if (tmp > 0 && end == n) return 0;
	return 1;
}

void Try(int k, int lastZero) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			for (int j = 0; j < 2; j++) {
				if (checkArray(i)) {
					arr[i] = parenthesis[j];
					if (i == lastZero) {
						if (checkArray(n)) printResult();
//						printResult();
					}
					else Try(k + 1, lastZero);
					arr[i] = 0;
				}
			}
			break;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int lastZero = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			lastZero = i;
			break;
		}
	}
	if (lastZero == -1 && checkArray(n)) printResult();
	Try(0, lastZero);
}
