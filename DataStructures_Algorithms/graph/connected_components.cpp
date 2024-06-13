#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int component_index;
	int val;
	struct Node *next;
}Node;

int num_nodes, num_edges;
int start_edge[10], end_edge[10];
int visited[10], component_index[10];
Node *list_adjacents[10], *preNode[10];

Node *makeNode(int val) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = val;
	p->component_index = -1;
	p->next = NULL;
	return p;
}

void printList(Node *head) {
	Node *tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

void makeListAdjacents() {
	for (int i = 0; i < num_edges; i++) {
		Node *u = makeNode(end_edge[i]);
		Node *v = makeNode(start_edge[i]);
		
		if (list_adjacents[start_edge[i]] == NULL) {
			list_adjacents[start_edge[i]] = makeNode(start_edge[i]);
			list_adjacents[start_edge[i]]->next = u;
		} else {
			preNode[start_edge[i]]->next = u;
		}
		preNode[start_edge[i]] = u;
		
		if (list_adjacents[end_edge[i]] == NULL) {
			list_adjacents[end_edge[i]] = makeNode(end_edge[i]);
			list_adjacents[end_edge[i]]->next = v;
		} else {
			preNode[end_edge[i]]->next = v;
		}
		preNode[end_edge[i]] = v;
	}
}

void DFS(Node *u, int component_id) {
	if (u == NULL) return;
	visited[u->val] = 1;
	component_index[u->val] = component_id;
//	printf("%d %d\n", u->val, u->component_index);
	
	for (Node *adjs = list_adjacents[u->val]->next; adjs != NULL; adjs = adjs->next) {
		if (!visited[adjs->val]) DFS(adjs, component_id);
	}
}

void count_connected_components() {
	for (int i = 1; i <= num_nodes; i++) {
		list_adjacents[i] = NULL;
		preNode[i] = NULL;
	}
	makeListAdjacents();
	int component_id = 0;
	
	for (int i = 1; i <= num_nodes; i++) {
		if (!visited[i]) {
//			printf("%d ", i);
			component_id += 1;
			DFS(list_adjacents[i], component_id);
		}
	}
	
	printf("Number of components: %d\n", component_id);
}

int main() {
	scanf("%d %d", &num_nodes, &num_edges);
	
	for (int i = 0; i < num_edges; i++) {
		scanf("%d %d", &start_edge[i], &end_edge[i]);
	}
	count_connected_components();
	for (int i = 1; i <= num_nodes; i++) {
		printf("Node %d - Component %d\n", i, component_index[i]);
	}
}


