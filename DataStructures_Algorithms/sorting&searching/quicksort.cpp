#include <stdio.h>
#define MAX_LENGTH 1000001
int a[MAX_LENGTH];
int x[MAX_LENGTH], y[MAX_LENGTH];

int Partition(int arr[], int start, int end) {
	int mid = (start + end)/2;
	
	int tmp = arr[mid], count1 = -1, count2 = -1;
	for (int i = start; i < end; i++) {
		if (i != mid) {
			if (arr[i] < tmp) x[++count1] = arr[i];
			else y[++count2] = arr[i]; 
		}
	}

	int pivot = -1;
	if (count1 == -1) {
		// arr[i] >= tmp, all i
		int tmp1 = -1;
		for (int i = start; i < end; i++) {
			if (i > start) arr[i] = y[++tmp1];
			else arr[i] = tmp;
		}
		pivot = start;
	} else if (count2 == -1) {
		int tmp2 = -1;
		for (int i = start; i < end; i++) {
			if (i < end - 1) arr[i] = x[++tmp2];
			else arr[i] = tmp;
		}
		pivot = end - 1;
	} else {
		int tmp1 = -1, tmp2 = -1;
		for (int i = start; i < end; i++) {
			if (i < start + count1 + 1) arr[i] = x[++tmp1];
			else if (i == start + count1 + 1) arr[i] = tmp;
			else arr[i] = y[++tmp2];
		}
		pivot = start + count1 + 1;
	}
//	printf("%d\n", pivot);
//	for (int i = start; i < end; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
	return pivot;
}

void quickSort(int arr[], int start, int end) {
	if (end - start <= 1) return;
	if (end - start == 2) {
		if (arr[end - 1] < arr[start]) {
			int tmp = arr[end - 1];
			arr[end - 1] = arr[start];
			arr[start] = tmp;
		} 
		return;
	}
	int pivot = Partition(arr, start, end);
//	for (int i = start; i < end; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
	quickSort(arr, start, pivot);
	quickSort(arr, pivot + 1, end);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
	quickSort(a, 0, n);
//	int t = Partition(a, 0, 5);
//	int t2 = Partition(a, 0, t);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

