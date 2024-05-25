#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	int val;
	struct TNode *leftmost_child;
	struct TNode *right_sibling;
}TNode;

TNode *makeNode(int val) {
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
	printf("%d ", root->val);
	
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
	printf("%d ", root->val);
}

void inorder(TNode *root) {
	if (root == NULL) return;
	
	TNode *tmp = root->leftmost_child;
	inorder(tmp);
	printf("%d ", root->val);
	
	while (tmp != NULL) {
		tmp = tmp->right_sibling;
		inorder(tmp);
	}
}

TNode *checkExist(TNode *root, int nodeID) {
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

TNode *insert(TNode *root, int insertID, int oldID) {
	TNode *oldNode = checkExist(root, oldID);
	if (oldNode == NULL) return NULL;
	
	TNode *insertNode = checkExist(root, insertID);
	if (insertNode != NULL) return NULL;
	
	insertNode = makeNode(insertID);
	if (oldNode->leftmost_child == NULL) {
		oldNode->leftmost_child = insertNode;
	} else {
		TNode *tmp = oldNode->leftmost_child;
		while (tmp->right_sibling != NULL) {
			tmp = tmp->right_sibling;
		}
		tmp->right_sibling = insertNode;
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
		} else if (strcmp(s, "Insert") == 0) {
			scanf("%d %d", &u, &v);
			root = insert(root, u, v);
		} else if (strcmp(s, "PreOrder") == 0) {
			preorder(root);
		} else if (strcmp(s, "PostOrder") == 0) {
			postorder(root);
		} else if (strcmp(s, "InOrder") == 0) {
			inorder(root);
		} else break;
	}
}
