#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *head1 = NULL, *tail = NULL;
struct ListNode *head2;
struct ListNode *head;

struct ListNode *makeNode(int val){
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = NULL;
    return p;
}

void enqueue(int val){
    struct ListNode *p = makeNode(val);
    if (head1 == NULL) {
        head1 = p; tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

void push(int val){
    struct ListNode *p = makeNode(val);
    if (head2 == NULL) {
        head2 = p;
        return;
    }
    struct ListNode *tmp = head2;
    head2 = p;
    head2->next = tmp;
}

int countList(struct ListNode *head){
    if (head == NULL) return 0;
    struct ListNode *tmp = head;
    int count = 0;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}

struct ListNode *reorderList(struct ListNode *head) {
    if (head->next == NULL) {
        return head;
    }
    struct ListNode *tmp1 = head, *tmp2;
    int numNodes = countList(head);

    for (int i = 1; i <= numNodes; i++){
        if (i <= numNodes/2) {
            enqueue(tmp1->val);
            if (i == numNodes/2){
                tail->next = NULL;
            }
        } else {
            push(tmp1->val);
            if (i == numNodes/2 + 1){
                tmp2 = head2;
                tmp2->next = NULL;
            }
        }
        tmp1 = tmp1->next;
    }
    head = head1;
    for (int i = 1; i <= numNodes/2; i++){
        tmp1 = head1; tmp2 = head2;
        head1 = head1->next; head2 = head2->next;
        tmp1->next = tmp2;
        if (numNodes % 2 == 0) tmp2->next = head1;
        else{
            if (i < numNodes/2) tmp2->next = head1;
            else tmp2->next = head2; 
        }
    }
    return head;
}

int main(){
	struct ListNode *preNode;
	for (int i = 0; i < 11; i++){
		struct ListNode *tmp = makeNode(i*10);
		if (i == 0) head = tmp;
		else preNode->next = tmp;
		preNode = tmp;
	}
	head = reorderList(head);
	while (head != NULL){
		printf("%d ", head->val);
		head = head->next;
	}
}
