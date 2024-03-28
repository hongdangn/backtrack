#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
} Node;

Node* makeNode(int val){
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = val;
	p->next = NULL;
	return p;
}

void printList(Node* h){
	Node* p = h;
	while(p != NULL){
		printf("%d ", p->value);
		p = p->next;
	}
}


int main(){
	Node* head = makeNode(10);
	Node* node1 = makeNode(20);
	Node* node2 = makeNode(30);
	
	head->next = node1;
	node1->next = node2;
	printList(head);
	return 0;
}
