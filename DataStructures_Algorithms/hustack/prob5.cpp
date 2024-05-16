#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int key;
	struct Node *prev;
	struct Node *next;
}Node;

Node *head, *last;
char s[11];
int n, a[1001];
int key;

Node *makeNode(int key) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->key = key;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

void addlast(int key) {
	Node *p = makeNode(key);
	if (head == NULL) {
		head = p; last = p;
		return;
	}
	Node *tmp = head;
	while (tmp != NULL) {
		if (tmp->key == key) return;
		tmp = tmp->next;
	}
	last->next = p;
	p->prev = last;
	last = p;
}

void addfirst(int key) {
	Node *p = makeNode(key);
	if (head == NULL) {
		head = p; last = p;
		return;
	}
	Node *tmp = head;
	while (tmp != NULL) {
		if (tmp->key == key) return;
		tmp = tmp->next;
	}
	head->prev = p;
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
			p->prev = tmp2;
			
			if (nextNode != NULL) {
				nextNode->prev = p;
			} else last = p;
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
	Node *p = makeNode(u);
	while (tmp2 != NULL) {
		if (tmp2->key == v) {
			Node *prevNode = tmp2->prev;
			
			tmp2->prev = p;
			p->next = tmp2;
			p->prev = prevNode;
			
			if (prevNode != NULL) prevNode->next = p;
			else head = p;
		}
		tmp2 = tmp2->next;
	}
}

void removeNode(int key) {
	if (head == NULL) return;
	if (head->key == key) {
		if (head->next == NULL) {
			free(head); free(last);
		} else {
			Node *tmp = head;
			head = head->next;
			free(tmp);
		}
		return;
	}
	
	if (last->key == key) {
		if (last->prev == NULL) {
			free(head); free(last);
		} else {
			Node *tmp = last;
			last = last->prev;
			free(tmp);
		}
		return;
	}
	
	Node *tmp = head;
	
	while (tmp != NULL) {
		if (tmp->key == key) {
			Node *preNode = tmp->prev;
			Node *nextNode = tmp->next;
			
			preNode->next = nextNode;
			nextNode->prev = preNode;
			free(tmp);
			break;
		} 
		tmp = tmp->next;
	}
	return;
}

void reverse() {
	if (head == NULL || head->next == NULL) return;
	
	last = head;
	Node *tmp = head;
	tmp = tmp->next;
	head->next = NULL;
	head->prev = tmp;
	
	while (tmp != NULL) {
		Node *nextNode = tmp->next;		
		Node *preNode = tmp->prev;
		
		if (nextNode == NULL) {
			head = tmp;
		}
		tmp->next = preNode;
		tmp->prev = nextNode;
//		preNode->prev = tmp;
		tmp = nextNode;
	}
}

void printList(int output) {
	if (output) {
		Node *tmp = head;
		while (tmp != NULL) {
			printf("%d ", tmp->key);
			tmp = tmp->next;
		}
		printf("\n");
	} else {
		Node *tmp = last;
		while (tmp != NULL) {
			printf("%d ", tmp->key);
			tmp = tmp->prev;
		}
		printf("\n");
	}
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
		else {
			preNode->next = tmp;
			tmp->prev = preNode;
		}
		preNode = tmp;
		
		if (i == n - 1) last = tmp;
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
		} else if (strcmp(s, "output") == 0){
			scanf("%d", &key);
			printList(key);
		} else break;
	}
}

