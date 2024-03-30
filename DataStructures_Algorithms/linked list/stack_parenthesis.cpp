#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
	char value;
	struct Node *next;
};

char s[101];
Node *top;

Node *makeNode(char val){
	Node *p = (Node*)malloc(sizeof(Node));
	if (p == NULL){
		printf("ERROR....");
		exit(1);
	}
	p->value = val;
	p->next = NULL;
	return p;
}

void push(char val){
	Node *p = makeNode(val);
	p->next = top;
	top = p;
}

char pop(){
	if (top == NULL) return ' ';
	else{
		Node *tmp = top;
		top = top->next;
		char res = tmp->value;
		free(tmp);
		return res;
	}
}

int match(char a, char b){
	if (a == '{' && b == '}') return 1;
	if (a == '(' && b == ')') return 1;
	if (a == '[' && b == ']') return 1;
	return 0;
}

int check(char *s){
	for (int i = 0; i < strlen(s); i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
			push(s[i]);
		}
		else{
			char a = pop();
			if (!match(a, s[i])) return 0;
		}
	}
	if (top != NULL) return 0;
	return 1;
}

int main(){
	scanf("%s", &s);
	printf("%d", check(s));
}




