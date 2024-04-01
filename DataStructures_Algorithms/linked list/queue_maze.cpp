#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    int step;
    struct Node *next;
}Node;

int c[101][101], visited[101][101];
int m, n;
int startRow, startCol;
Node *head, *tail;
int drow[] = {0, 0, -1, 1};
int dcol[] = {1, -1, 0, 0};

Node *makeNode(int row, int col, int step){
    Node *p = (Node*)malloc(sizeof(Node));
    p->row = row; p->col = col;
    p->step = step;
    p->next = NULL;
}

int isEmpty(){
    if (head == NULL) return 1;
    return 0;
}

void enqueue(int row, int col, int step){
    Node *p = makeNode(row, col, step);
    if (isEmpty()){
    	head = p; tail = p;
	}
	else{
		tail->next = p;
		tail = p;
	}
}

Node *dequeue(){
    if (isEmpty()) return head;
    Node *tmp = head;
    head = head->next;
    free(tmp);
    if (head == NULL) tail = NULL;
    return head;
}

int breakMaze(int row, int col){
	return (row == 0 || col == 0 || row == m - 1 || col == n - 1);
}

int findPath(int startRow, int startCol){
	if (breakMaze(startRow, startCol)) return 0;
	int res;
	int tmpRow, tmpCol;
	enqueue(startRow, startCol, 0);
	visited[startRow][startCol] = 1;
	while(!isEmpty()){
		for (int i = 0; i < 4; i++){
			tmpRow = startRow + drow[i]; tmpCol = startCol + dcol[i];
			if (!visited[tmpRow][tmpCol] && !c[tmpRow][tmpCol]){
				if (breakMaze(tmpRow, tmpCol)){
					res = head->step + 1;
					return res;
				}
				enqueue(tmpRow, tmpCol, head->step + 1);
				visited[tmpRow][tmpCol] = 1;
			} 
		}
		head = dequeue();
		startRow = head->row; startCol = head->col;
	}
	return res;
}
int main(){
    scanf("%d %d", &m, &n);
    scanf("%d %d", &startRow, &startCol);
    for (int i = 0; i < m; i++){
    	for (int j = 0; j < n; j++){
    		scanf("%d", &c[i][j]);
		}
	}
	printf("%d", findPath(startRow, startCol));
}
