#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int value;
	struct Node* next;
};

Node* makeNode(int val){
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL){
		printf("What a fucking Error!");
		exit(1);
	}
	tmp->value = val;
	tmp->next = NULL;
	return tmp;
}

void printNode(Node *h){
	Node *p = h;
	while(p != NULL){
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}

Node* insertHead(int val, Node* h){
	Node *newHead = makeNode(val);
	newHead->next = h;
	return newHead;
}

int main(){
	Node *head, *preNode;
	for (int i = 0; i < 10; i++){
		Node *tmp = makeNode(i*10);
		if (i == 0){
			head = tmp;
		}
		else preNode->next = tmp;
		preNode = tmp;
	}
	printNode(head);
	Node *newHead = insertHead(-10, head);
	printNode(newHead);
}
