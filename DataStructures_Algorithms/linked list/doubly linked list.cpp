#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int val;
	struct Node *next;
	struct Node *prev;
}Node;

Node *makeNode(int val) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void printList(Node *randNode) {
	if (randNode == NULL) return;
	Node *tmp;
	if (randNode->prev == NULL) tmp = randNode;
	while(randNode->prev != NULL) {
		tmp = randNode->prev;
		randNode = randNode->prev;
	} 
	
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

Node *appendNode(char s[], Node *randNode, int val) {
	if (randNode == NULL) return NULL;
	
	Node *p = makeNode(val);
	if (strcmp(s, "before") == 0) {
		if (randNode->prev == NULL) {
			randNode->prev = p;
			p->next = randNode;
		} else {
			Node *tmp = randNode->prev;
			tmp->next = p;
			p->prev = tmp;
			randNode->prev = p;
			p->next = randNode;
		}
	} else {
		if (randNode->next == NULL) {
			randNode->next = p;
			p->prev = randNode;
		} else {
			Node *tmp = randNode->next;
			tmp->prev = p;
			p->next = tmp;
			randNode->next = p;
			p->prev = randNode;
		}
	}
	return p;
}

int main() {
	Node *p1 = makeNode(0);
	Node *tmp = appendNode("before", p1, 1);
	appendNode("after", tmp, 2);
	appendNode("before", tmp, 3);
	appendNode("after", tmp, 4);
	printList(tmp);
}
