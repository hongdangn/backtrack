#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char s[101], t[101];
int count[101][101];

int findPos(int end, char ch){
	int res = -1;
	char *tmp = strchr(s, ch);
	while (tmp != NULL){
		int pos = tmp - s;
		if (pos > end) break;
		else{
			res = pos;
			tmp = strchr(s + pos + 1, ch);
		}
	}
	return res;
	
}

void solve(){
	char *p = strchr(s, t[0]);
	if (p != NULL){
		int pos = p - s;
		for (int i = pos; i < strlen(s); i++) count[i][0] = 1;
	}
	for (int j = 1; j < strlen(t); j++){
		for (int i = 0; i < strlen(s); i++){
			int pos = findPos(i, t[j]);
			if (pos == -1) count[i][j] = count[i][j - 1];
			else{
				if (!pos) count[i][j] = count[i][j - 1] > 1? count[i][j - 1] : 1;
				else count[i][j] = count[i][j - 1] > count[pos - 1][j - 1] + 1? 
								   count[i][j - 1] : count[pos - 1][j - 1] + 1;
			}
		}
	}
	printf("Max length: %d", count[strlen(s) - 1][strlen(t) - 1]);
}

int main(){
	scanf("%s %s", &s, &t);
	solve();
}
