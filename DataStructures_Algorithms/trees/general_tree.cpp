#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	char val;
	struct TNode *leftmost_child;
	struct TNode *right_sibling;
}TNode;

TNode *makeNode(char val) {
	TNode *node = (TNode*)malloc(sizeof(TNode));
	if (node == NULL) {
		printf("Error"); exit(1);
	}
	node->val = val;
	node->leftmost_child = NULL;
	node->right_sibling = NULL;
	return node;
}

void preorder(TNode *root) {
	if (root == NULL) return;
	printf("%c ", root->val);
	
	TNode *tmp = root->leftmost_child;
	while (tmp != NULL) {
		preorder(tmp);
		tmp = tmp->right_sibling;
	}
}

void postorder(TNode *root) {
	if (root == NULL) return;
	TNode *tmp = root->leftmost_child;
	
	while (tmp != NULL) {
		postorder(tmp);
		tmp = tmp->right_sibling;
	}
	printf("%c ", root->val);
}

void inorder(TNode *root) {
	if (root == NULL) return;
	
	TNode *tmp = root->leftmost_child;
	inorder(tmp);
	printf("%c ", root->val);
	
	while (tmp != NULL) {
		tmp = tmp->right_sibling;
		inorder(tmp);
	}
}

int treeHeight(TNode *root) {
	if (root == NULL) return 0;
	
	int maxHeight = treeHeight(root->leftmost_child);
	TNode *tmp = root->leftmost_child;
	
	while (tmp != NULL) {
		tmp = tmp->right_sibling;
		int tmpHeight = treeHeight(tmp);
		if (maxHeight < tmpHeight) maxHeight = tmpHeight;
	}
	return maxHeight + 1;
}

int numLeaf(TNode *root) {
	if (root == NULL) return 0;
	if (root->leftmost_child == NULL) return 1;
	
	TNode *tmp = root->leftmost_child;
	int allLeaf = numLeaf(tmp);
	
	while (tmp != NULL) {
		tmp = tmp->right_sibling;
		allLeaf += numLeaf(tmp);
	}
	return allLeaf;
}

int countNode_kChild(TNode *root, int k) {
	if (root == NULL) return 0;
	if (k < 0) return 0;
	
	TNode *tmp = root->leftmost_child;
	int numNode = 0, child = 0;
	while (tmp != NULL) {
		child += 1;
		numNode += countNode_kChild(tmp, k);
		tmp = tmp->right_sibling;
	}
	if (child == k) numNode++;
	return numNode;
}

TNode *checkExist(TNode *root, char nodeID) {
	if (root == NULL) return NULL;
	if (root->val == nodeID) return root;
	
	TNode *tmp = root->leftmost_child;
	while (tmp != NULL) {
		TNode *existNode = checkExist(tmp, nodeID);
		if (existNode) return existNode;
		tmp = tmp->right_sibling;
	}
	return NULL;
}

int main(){
	TNode *nutA,*nutB,*nutC,*nutD,*nutE,*nutF,*nutG,*nutH,*nutI,*nutJ,*nutK;
	
	nutA = makeNode('A');
	nutB = makeNode('B');
	nutC = makeNode('C');
	nutD = makeNode('D');
	nutE = makeNode('E');
	nutF = makeNode('F');
	nutG = makeNode('G');
	nutH = makeNode('H');
	nutI = makeNode('I');
	nutJ = makeNode('J');
	nutK = makeNode('K');
	
	TNode *root = nutA;
	
	nutA->leftmost_child = nutB;
	
	nutB->leftmost_child = nutE;
	nutB->right_sibling = nutC;
	
	nutC->leftmost_child = nutG;
	nutC->right_sibling = nutD;
	
	nutE->right_sibling = nutF;
	
	nutG->leftmost_child = nutH;
	
	nutH->right_sibling = nutI;
	nutI->right_sibling = nutJ;
	nutJ->right_sibling = nutK;
	
	printf("\nDuyet trc:\n");
	preorder(root);
	printf("\nDuyet sau:\n");
	postorder(root);
	printf("\nDuyet giua:\n");
	inorder(root);
	printf("\nChieu cao:%d\n",treeHeight(root));
	printf("\nSo nut la:%d\n",numLeaf(root));
	printf("\nSo nut co 0 con:%d\n",countNode_kChild(root,0));
	printf("\nSo nut co 1 con:%d\n",countNode_kChild(root,1));
	printf("\nSo nut co 4 con:%d\n",countNode_kChild(root,4));
	
	TNode *tmp = checkExist(root, 'A');
	tmp->leftmost_child = makeNode('L');
	printf("%c\n", root->leftmost_child->val);
	if (tmp != NULL) printf("Exist: %c", tmp->leftmost_child->right_sibling->val);
	return 0;	
}


