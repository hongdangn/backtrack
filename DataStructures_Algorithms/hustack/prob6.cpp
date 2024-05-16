#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int val;
	struct Node *next;
}Node;

int n, a[101];

Node *makeNode(int val) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	return p;
}

Node *pop(Node *head) {
	if (head == NULL) return NULL;
	Node *tmp = head; 
	head = head->next;
	free(tmp);
	return head;
}

Node *push(Node *head, int val) {
	Node *p = makeNode(val);
	if (head == NULL) {
		head = p;
		return head;
	}
	p->next = head; head = p;
	return head;
}

int isEmpty(Node *head) {
	if (head == NULL) return 1;
	return 0;
}

bool check(int index) {
	int count = 0;
	for (int i = 0; i <= index; i++) {
		if (a[i] == 1 || a[i] == 2 || a[i] == 3) count++;
		else count--;
		if (count < 0) return false;
	}
	return true;
}

bool finalCheck() {	
	Node *head = NULL;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1 || a[i] == 2 || a[i] == 3) {
			head = push(head, a[i]);
		}
		else if (a[i] - head->val == 3) {
			head = pop(head);
		} else return false;
	}
	if (isEmpty(head)) return true;
	return false;
}

void printArr() {
	for (int l = 0; l < n; l++) {
		printf("%d", a[l]);
	}
	printf(" ");
}

void Try(int k, int numQuesMark) {
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			for (int j = 1; j <= 6; j++) {
				a[i] = j;
				if (check(i)) {
					if (k == numQuesMark - 1) {
						if (finalCheck()) printArr();
					} 
					else Try(k + 1, numQuesMark);
				}  
				a[i] = 0;
			}
			break;
		} 
	}
//	if (k == n) {
//		if (finalCheck()) printArr();
//	} else {
//		if (a[k] == 0) {
//			for (int i = 1; i <= 6; i++) {
//				a[k] = i;
//				if (check(k)) Try(k + 1);
//				a[k] = 0;
//			}
//		} else Try(k + 1);
//	}
}

int main() {
	int numQuesMark = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) numQuesMark++;
	}
	if (numQuesMark == 0) {
		if (finalCheck()) printArr();
		return 0;
	}
	Try(0, numQuesMark);
}


