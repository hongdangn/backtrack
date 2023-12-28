#include <stdio.h>
#include <string.h>

char s[100];
int main()
{
	scanf("%s", &s);
	int n = strlen(s);
	for(int i = 0; i < n/2; i++){
		if(s[i] > s[n - 1 - i] || (s[i + 1] < s[n - 1 - i] && i + 1 < n - 1 - i)){
			printf("false");
			return 0;
		}
	}
	printf("true");
}
