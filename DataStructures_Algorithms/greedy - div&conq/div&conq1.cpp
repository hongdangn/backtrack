#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double a;
int n;

double power(double a, int n){
	double res;
	if (n == 0) res = 1;
	else{
		if (n % 2 == 0) res = power(a, n/2) * power(a, n/2);
		else res = a * power(a, (n - 1)/2) * power(a, (n - 1)/2);
	}
	return res;
}

int main(){
	scanf("%lf %d", &a, &n);
	printf("%lf", power(a, n));
}
