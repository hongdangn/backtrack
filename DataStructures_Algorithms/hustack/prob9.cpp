#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	int val;
	struct TNode *left;
	struct TNode *right;
}TNode;

TNode *makeNode(int val) {
	TNode *node = (TNode*)malloc(sizeof(TNode));
	if (node == NULL) {
		printf("Error"); exit(1);
	}
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void preorder(TNode *root) {
	if (root == NULL) return;
	printf("%d ", root->val);
	
	preorder(root->left);
	preorder(root->right);
}

void postorder(TNode *root) {
	if (root == NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

void inorder(TNode *root) {
	if (root == NULL) return;
	
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

TNode *checkExist(TNode *root, int nodeID) {
	if (root == NULL) return NULL;
	if (root->val == nodeID) return root;
	
	TNode *existL = checkExist(root->left, nodeID);
	if (existL != NULL) return existL;
	else {
		TNode *existR = checkExist(root->right, nodeID);
		if (existR != NULL) return existR;
	}
	return NULL;
}

TNode *addLeft(TNode *root, int insertID, int oldID) {
	TNode *oldNode = checkExist(root, oldID);
	if (oldNode == NULL) return root;
	if (oldNode->left == NULL) {
		TNode *insertNode = checkExist(root, insertID);
		if (insertNode != NULL) return root;
		
		insertNode = makeNode(insertID);
		oldNode->left = insertNode;
	}
	return root;
}

TNode *addRight(TNode *root, int insertID, int oldID) {
	TNode *oldNode = checkExist(root, oldID);
	if (oldNode == NULL) return root;
	if (oldNode->right == NULL) {
		TNode *insertNode = checkExist(root, insertID);
		if (insertNode != NULL) return root;
		
		insertNode = makeNode(insertID);
		oldNode->right = insertNode;
	}
	return root;
}

int main() {
	char s[15]; int u, v;
	TNode *root = NULL;
	
	while (1) {
		scanf("%s", &s);
		if (strcmp(s, "MakeRoot") == 0) {
			scanf("%d", &u);
			root = makeNode(u);
		} else if (strcmp(s, "AddLeft") == 0) {
			scanf("%d %d", &u, &v);
			root = addLeft(root, u, v);
		} else if (strcmp(s, "AddRight") == 0) {
			scanf("%d %d", &u, &v);
			root = addRight(root, u, v);
		} else if (strcmp(s, "PreOrder") == 0) {
			preorder(root);
		} else if (strcmp(s, "PostOrder") == 0) {
			postorder(root);
		} else if (strcmp(s, "InOrder") == 0) {
			inorder(root);
		} else break;
	}
}
