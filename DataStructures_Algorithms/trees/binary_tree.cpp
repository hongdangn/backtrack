#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	int key;
	struct TNode *left;
	struct TNode *right;
//	struct TNode *parent;
}TNode;

// moi y thuoc cay con trai cua x: key(y) < key(x) 
// moi y thuoc cay con phai cua x: key(y) > key(x)

TNode *makeNode(int key) {
	TNode *node = (TNode*)malloc(sizeof(TNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TNode *findMin_Node(TNode *root) {
	if (root == NULL) return root;
	if (root->left == NULL) return root;
	
	TNode *tmp = findMin_Node(root->left);
	return tmp;
}

TNode *findMax_Node(TNode *root) {
	if (root == NULL) return root;
	if (root->right == NULL) return root;
	
	TNode *tmp = findMin_Node(root->right);
	return tmp;
}

// Predecessor (ke can sau) cua nut x -> nut y: key(y) > key(x) va key(y) min
// Successor (ke can truoc) cua nut x -> nut y: key(y) < key(x) va key(y) max

TNode *search(TNode *root, int val) {
	if (root == NULL) return NULL;
	
	if (root->key == val) return root;
	if (root->key > val) {
		return search(root->left, val);
	} else return search(root->right, val);
}

TNode *insert(TNode *root, int val) {
//	if (search(root, val) != NULL) return NULL;
	
	if (root == NULL) {
		root = makeNode(val);
	} else if (root->key > val) {
		root->left = insert(root->left, val);
	} else {
		root->right = insert(root->right, val);
	} 
	return root;
}

TNode *delete(TNode *root, int val) {
	if (search(root, val) == NULL) return NULL;
	
	if (root== NULL) return NULL;
	if (root->key > val) {
		root->left = delete(root->left, val);
	} else if (root->key < val) {
		root->right = delete(root->right, val)
	} else if (root->right != NULL && root->left != NULL) {
		TNode *minNode = findMin_Node(root->right);
		root->key = minNode->key;
		
	}
}
 
