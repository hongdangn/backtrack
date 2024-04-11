#include <stdio.h>
#include <stdlib.h>

typedef struct Poly {
	int coeff;
	int power;
	struct Poly *next;	
}Poly;

Poly *makePoly(int coeff, int power) {
	Poly *p = (Poly*)malloc(sizeof(Poly));
	p->coeff = coeff;
	p->power = power;
	p->next = NULL;
	return p;
}

void viewPoly(Poly *poly) {
	Poly *tmp = poly;
	while (tmp != NULL) {
		printf("%d|%d -> ", tmp->coeff, tmp->power);
		tmp = tmp->next;
	}
}

void sumTwoPoly(Poly *poly1, Poly *poly2) {
	Poly *head;
	
	viewPoly(poly1);
	printf("\n");
	viewPoly(poly2);
	printf("\n");
	
	if (poly1 == NULL) head = poly2;
	if (poly2 == NULL) head = poly1;
	
	if (poly1 != NULL && poly2 != NULL) {
		if (poly1->power > poly2->power) {
			head = poly1; 
			poly1 = poly1->next;
		}
		else if (poly1->power < poly2->power) {
			head = poly2; 
			poly2 = poly2->next;
		} else {
			head = makePoly(poly1->coeff + poly2->coeff, 
								 poly1->power);
			poly1 = poly1->next; poly2 = poly2->next;
		}
		Poly *preNode = head, *tmp;
		
		while (poly1 != NULL && poly2 != NULL) {
			if (poly1->power > poly2->power) {
				preNode->next = poly1; preNode = poly1;
				poly1 = poly1->next;
			} else if (poly1->power < poly2->power) {
				preNode->next = poly2; preNode = poly2;
				poly2 = poly2->next;				
			} else {
				if (poly1->coeff + poly2->coeff == 0) {
					poly1 = poly1->next; poly2 = poly2->next;
					continue;
				}
				tmp = makePoly(poly1->coeff + poly2->coeff, 
							   poly1->power);
				preNode->next = tmp; preNode = tmp;
				poly1 = poly1->next; poly2 = poly2->next;
			}
		}
		
		while (poly1 != NULL) {
			preNode->next = poly1; preNode = poly1;
			poly1 = poly1->next;
		}
		
		while (poly2 != NULL) {
			preNode->next  = poly2; preNode = poly2;
			poly2 = poly2->next;
		}
	}
	viewPoly(head);
	printf("\n");
}

int main() {
	int coeff[] = {-5, 3, 10, 7, 2, 3, -10, 8};
	int power[] = {10, 8, 3, 2, 9, 8, 3, 2};
	
	Poly *poly1, *preNode1;
	Poly *poly2, *preNode2;
	
	for (int i = 0; i < 4; i++){
		Poly *tmp = makePoly(coeff[i], power[i]);
		if (i == 0) poly1 = tmp;
		else preNode1->next = tmp;
		preNode1 = tmp;
	}
	
	for (int i = 4; i < 8; i++){
		Poly *tmp = makePoly(coeff[i], power[i]);
		if (i == 4) poly2 = tmp;
		else preNode2->next = tmp;
		preNode2 = tmp;
	}
	
	sumTwoPoly(poly1, poly2);
}
