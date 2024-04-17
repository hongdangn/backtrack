#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_INT 101
int c, d, x, y;
int res = MAX_INT;
int arr1[15], arr2[15];
int res1[15], res2[15];

int gcd(int a, int b) {
	if (a == 0) {
		if (b == 0) return MAX_INT;
		return b;
	} else if (b == 0) return a;
	
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

void Try(int k) {
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			int tmp = c;
			c = d;
			d = tmp;
		} else if (i == 1) {
			c += d;
		} else c -= d;
		
		arr1[k] = c; arr2[k] = d;
		
		if (c == x && d == y) {
			if (k <= res) {
				int tmp = 0;
				for (int i = 1; i <= k; i++) {
					if (arr1[i] < 0 || arr2[i] < 0) tmp = 1;
				}
				if (!tmp) {
					res = k;
					for (int i = 1; i <= k; i++) {
						res1[i] = arr1[i]; res2[i] = arr2[i];
					}
				}
			}
		} else if (k != 13) {
			Try(k + 1);
		}
		
		if (i == 0) {
			int tmp = c;
			c = d;
			d = tmp;
		} else if (i == 1) c -= d;
		else c += d;
	}
}

int main() {
	scanf("%d %d %d %d", &c, &d, &x, &y);
	if (gcd(x, y) != gcd(c, d)) printf("-1");
	else {
		if (c == x && d == y) printf("0 (%d %d)", c, d);
		else {
			res1[0] = c; res2[0] = d;
			Try(1);
			printf("%d ", res);
			for (int i = 0; i < res; i++) {
				printf("(%d %d) ", res1[i], res2[i]);
			}
			printf("(%d %d)", x, y);
		}
	}
}
