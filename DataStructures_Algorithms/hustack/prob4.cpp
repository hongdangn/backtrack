#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int val;
	struct Node *next;
}Node;

Node *head1, *head2;
int a[1001], b[1001];
int n, m;
char s[7];

Node *makeNode(int val) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	return p;
}

Node *makeList(Node *head, int arr[], int length) {
	Node *preNode, *tmp;
	for (int i = 0; i < length; i++) {
		tmp = makeNode(arr[i]);
		if (i == 0) head = tmp;
		else preNode->next = tmp;
		preNode= tmp;
	}
	return head;
}

Node *reverseList(Node *head) {
	if (head == NULL || head->next == NULL) return head;
	
	Node *preNode = NULL, *tmp = head;
	while (tmp->next != NULL) {
		Node *tmp1 = tmp->next;
		tmp->next = preNode;
		preNode = tmp;
		tmp = tmp1;
	}
	tmp->next = preNode;
	head = tmp;
	return head;
}

Node *mergeIncreaseList(Node *head1, Node *head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	
	Node *head, *preNode;
	if (head1->val <= head2->val) {
		head = head1;
		head1 = head1->next;
	} else {
		head = head2;
		head2 = head2->next;
	}
	preNode = head;
	while (head1 != NULL && head2 != NULL) {
		if (head1->val <= head2->val) {
			preNode->next = head1;
			preNode = head1;
			head1 = head1->next;
		} else {
			preNode->next = head2;
			preNode = head2;
			head2 = head2->next;
		}
	}
	
	while (head1 != NULL) {
		preNode->next = head1;
		preNode = head1;
		head1 = head1->next;
	}
	
	while (head2 != NULL) {
		preNode->next = head2;
		preNode = head2;
		head2 = head2->next;
	}
	
	return head;
}

void printList(Node *head) {
	Node *tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	head1 = makeList(head1, a, n);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	head2 = makeList(head2, b, m);

	scanf("%s", &s);
	if (head1->next != NULL) {
		if (head1->val > head1->next->val) {
			head1 = reverseList(head1);
		}
	}
	
	if (head2->next != NULL) {
		if (head2->val > head2->next->val) {
			head2 = reverseList(head2);
		}
	}
	Node *head;
	head = mergeIncreaseList(head1, head2);
	
	if (strcmp(s, "iSort") == 0) {
		printList(head);
	} else {
		head = reverseList(head);
		printList(head);
	}
}
