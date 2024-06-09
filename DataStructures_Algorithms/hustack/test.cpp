#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree {
	int val;
	struct Tree *left;
	struct Tree *right;
}Tree;

char s[10];
int node;

Tree *makeNode(int val) {
	Tree *p = (Tree*)malloc(sizeof(Tree));
	p->val = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void preorder(Tree *root) {
	if (root == NULL) return;
	printf("%d ", root->val);
	
	preorder(root->left);
	preorder(root->right);
}

int existNode(int val, Tree *root) {
	if (root == NULL) return 0;
	if (root->val == val) return 1;
	
	if (val > root->val) return existNode(val, root->right);
	return existNode(val, root->left);
}

Tree *insert(int val, Tree *root) {
	if (root == NULL) {
		root = makeNode(val);
		return root;
	} else if (root->val < val) {
		root->right = insert(val, root->right);
	} else {
		root->left = insert(val, root->left);
	}
	return root;
}

int main() {
	Tree *root = NULL;
	while(1) {
		scanf("%s", &s);
		if (strcmp(s, "#") == 0) break;
		scanf("%d", &node);
		if (existNode(node, root) == 0) {
			root = insert(node, root);
		} 
	}
	preorder(root);
}
