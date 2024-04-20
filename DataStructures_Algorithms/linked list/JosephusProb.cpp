#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int val;
	struct Node *next;
	struct Node *prev;
} Node;

int m, n;
Node *head;

Node *makeNode(int val) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

Node *deleteNode(Node *p) {
	if (p->next == NULL) {
		free(p);
		return NULL;
	}
	
	Node *prevNode = p->prev;
	Node *nextNode = p->next;
	
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	free(p);
	return nextNode;
}

void solveJosephus() {
	while (head->val != head->next->val) {
		int start = 1;
		while (start < 5) {
			head = head->next;
			start++;
		}
		printf("Xoa nguoi thu: %d\n", head->val);
		head = deleteNode(head);
	}
	printf("\nNguoi thang cuoc la: %d", head->val);
}

int main() {
	scanf("%d %d", &m, &n);
	
	Node *preNode, *tmp;
	for (int i = 0; i < n; i++) {
		tmp = makeNode(i + 1);
		if (i == 0) head = tmp;
		else {
			preNode->next = tmp;
			tmp->prev = preNode;
		}
		preNode = tmp;
	}
	tmp->next = head;
	head->prev = tmp;
	
	solveJosephus();
}
