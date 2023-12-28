#include <stdio.h>
#include <string.h>

char s[2001], t[2001];

int main()
{
	scanf("%s", &s);
	scanf("%s", &t);
	char *p = strstr(s, t);
	int tmp = 0;
	if(p == NULL){
		printf("-1");
		return 0;	
	}
	while(p != NULL){
		int tmp = p - s;
		printf("%d ", tmp + 1);
		p = strstr(p + 1, t);
	}
}

