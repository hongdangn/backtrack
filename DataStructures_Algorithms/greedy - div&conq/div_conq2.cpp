#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, a[101];

int solveMid(int a[], int mid){
	int maxLeft = -1e9, maxLeftTMP = 0;
	int maxRight = -1e9, maxRightTMP = 0;
	for(int i = mid; i >= 0; i--){
		maxLeftTMP += a[i];
		if (maxLeftTMP > maxLeft) maxLeft = maxLeftTMP;
	}
	for (int i = mid + 1; i < n; i++){
		maxRightTMP += a[i];
		if (maxRightTMP > maxRight) maxRight = maxRightTMP;
	}
	return maxLeft + maxRight;
}

int solve(int a[], int start, int end){
	int mid = (end - start)/2 + start;
	if (start == end) return a[start];
	else{
		int left = solve(a, start, mid - 1);
		int right = solve(a, mid + 1, end);
		int maxMid = solveMid(a, mid);
		int maxLR = left > right? left : right;
		return maxLR > maxMid? maxLR : maxMid;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d", solve(a, 0, n - 1));
}
