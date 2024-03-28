#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int value;
	struct Node* next;
}Node;

Node* makeNode(int val){
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL){
		printf("Dm: may loi roi");
		exit(1);
	}
	tmp->value = val;
	tmp->next = NULL;
	return tmp;
}

void findFirstNode(int val, Node* h){
	Node* p = h;
	int pos = 1, check = 0;
	while(p != NULL){
		if (p->value == val){
			printf("Dm NODE o vi tri %d.\n", pos);
			check = 1;
			break;
		}
		else{
			p = p->next;
			pos++;
		}
	}
	if (!check) {
		printf("Cha thay cai NODE nao sat.\n");
	}
	printf("%d", pos);
}

int main(){
	Node *head = makeNode(0), *preNode;
	for (int i = 1; i < 1000; i++){
		Node *tmp = makeNode(i*10);
		if (i == 1){
			head->next = tmp;
		}
		else {
			preNode->next = tmp;
		}
		preNode = tmp;
	}
	findFirstNode(401, head);
	return 0;
}
