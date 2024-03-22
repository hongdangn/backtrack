#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char s[101], t[101];
int count[101][101];

int findPos(char a[], int end, char ch){
	char* p = strchr(a, ch);
	if (p != NULL && p - a <= end) return 1;
	return 0;
}

void solve(){
	for (int i = 0; i < strlen(s); i++){
		count[i][0] = findPos(s, i, t[0]);
	}
	for (int j = 0; j < strlen(t); j++){
		count[0][j] = findPos(t, j, s[0]);
	}
	
	for (int i = 1; i < strlen(s); i++){
		for (int j = 1; j < strlen(t); j++){
			if (s[i] == t[j]) count[i][j] = count[i - 1][j - 1];
			else{
				count[i][j] = count[i][j - 1] > count[i - 1][j]? 
							  count[i][j - 1] : count[i - 1][j];
			}
		}
	}
	printf("Max string: %d", count[strlen(s) - 1][strlen(t) - 1]);
}

int main(){
	scanf("%s %s", &s, &t);
	solve();
}
