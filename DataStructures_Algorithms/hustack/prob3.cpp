#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int key;
	struct Node *next;
}Node;

Node *head;
char s[11];
int n, a[1001];
int key;

Node *makeNode(int key) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->key = key;
	p->next = NULL;
	return p;
}

void addlast(int key) {
	Node *p = makeNode(key);
	if (head == NULL) {
		head = p;
		return;
	}
	Node *tmp = head;
	while (tmp != NULL) {
		if (tmp->key == key) return;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = p;
}

void addfirst(int key) {
	Node *p = makeNode(key);
	if (head == NULL) {
		head = p;
		return;
	}
	Node *tmp = head;
	while (tmp != NULL) {
		if (tmp->key == key) return;
		tmp = tmp->next;
	}
	tmp = head;
	p->next = head;
	head = p;
}

void addafter(int u, int v) {
	if (head == NULL) return;
	Node *tmp1 = head, *tmp2 = head;
	while (tmp1 != NULL) {
		if (tmp1->key == u) {
			return;
		}
		tmp1 = tmp1->next;
	}
	Node *p = makeNode(u);
	while (tmp2 != NULL) {
		if (tmp2->key == v) {
			Node *nextNode = tmp2->next;
			tmp2->next = p;
			p->next = nextNode;
		}
		tmp2 = tmp2->next;
	}
	return;
}

void addbefore(int u, int v) {
	if (head == NULL) return;
	Node *tmp1 = head, *tmp2 = head;
	while (tmp1 != NULL) {
		if (tmp1->key == u) {
			return;
		}
		tmp1 = tmp1->next;
	}
	Node *p = makeNode(u), *preNode;
	if (head->key == v) {
		p->next = head;
		head = p;
		return;
	} 
	while (tmp2 != NULL) {
		if (tmp2->key == v) {
			preNode->next = p;
			p->next = tmp2;
		}
		preNode = tmp2;
		tmp2 = tmp2->next;
	}
}

void removeNode(int key) {
	if (head == NULL) return;
	if (head->key == key) {
		if (head->next == NULL) {
			free(head);
			return;
		} else {
			Node *tmp = head;
			head = head->next;
			free(tmp);
		}
	}
	
	Node *tmp = head->next, *preNode = head;
	while (tmp != NULL) {
		if (tmp->key == key) {
			Node *tmp1 = tmp;
			preNode->next = tmp->next;
			preNode = tmp->next;
			if (tmp->next == NULL) {
				break;
			}
			tmp = tmp->next->next;
			free(tmp1);
		} else {
			preNode = tmp;
			tmp = tmp->next;
		}
	}
	return;
}

void reverse() {
	if (head == NULL || head->next == NULL) return;
	
	Node *tmp = head, *preNode = NULL;
	while (tmp->next != NULL) {
		Node *tmp1 = tmp->next;
		tmp->next = preNode;
		preNode = tmp;
		tmp = tmp1;
	}
	tmp->next = preNode; 
	head = tmp;
	return;
}

void printList() {
	Node *tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->key);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	Node *preNode, *tmp;
	for (int i = 0; i < n; i++) {
		tmp = makeNode(a[i]);
		if (i == 0) head = tmp;
		else preNode->next = tmp;
		preNode= tmp;
	}
	
	while(true) {
		scanf("%s", &s);
		if (strcmp(s, "addlast") == 0) {
			scanf("%d", &key);
			addlast(key);
		} else if (strcmp(s, "addfirst") == 0) {
			scanf("%d", &key);
			addfirst(key);
		} else if (strcmp(s, "addafter") == 0) {
			int u, v;
			scanf("%d %d", &u, &v);
			addafter(u, v);
		} else if (strcmp(s, "addbefore") == 0) {
			int u, v;
			scanf("%d %d", &u, &v);
			addbefore(u, v);
		} else if (strcmp(s, "remove") == 0) {
			scanf("%d", &key);
			removeNode(key);
		} else if (strcmp(s, "reverse") == 0){
			reverse();
		} else {
			break;
		}
	}
	printList();
}

