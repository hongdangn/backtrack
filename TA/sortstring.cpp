#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[1001][129];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", &arr[i]);
//		pos[i] = i;
	}	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(strcmp(arr[i], arr[j]) > 0){
				char tmp[129] = "";
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp);
			}
		}
	}
	for(int i = n - 1; i >= 0; i--){
		printf("%s\n", arr[i]);
//		pos[i] = i;
	}	
}
