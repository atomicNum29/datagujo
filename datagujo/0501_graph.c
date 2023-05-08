#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NUM_VTX 6

typedef struct _NODE node;
struct _NODE {
	int vtx;
	node* next;
};
node* graph[NUM_VTX];

void _addEdge(int v1, int v2) {
	node* _new = (node*)malloc(sizeof(node)); // v1 -> v2
	_new->next = 0;
	_new->vtx = v2;

	if (graph[v1] == 0) {
		graph[v1] = _new;
	}
	else {
		node* temp = graph[v1];
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = _new;
	}
	return;
}

void addEdge(int v1, int v2) {
		
	// v1 --> v2
	_addEdge(v1, v2);
	// v2 --> v1
	_addEdge(v2, v1);
	return;
}

int isThereEdge(int v1, int v2) {
	node* temp = graph[v1];
	while (temp) {
		if (temp->vtx == v2) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

// DFS를 위한 stack 구현
int stack_dfs[NUM_VTX];
int top = -1;
void push(int _v) {
	if (top == NUM_VTX - 1) {
		return;
	}
	stack_dfs[++top] = _v;
	return;
}
int pop() {
	if (top == -1) {
		return -999;
	}
	return stack_dfs[top--];
}
// 스택 안에 _v가 있는 지 검사
int isInStack(int _v) {
	for (int i = 0; i <= top; i++) {
		if (stack_dfs[i] == _v) {
			return 1;
		}
	}
	return 0;
}

void do_DFS(int _v) {
	// 방문 처리 용 배열
	int visited[NUM_VTX] = { 0, };
	push(_v);
	while (top != -1) {
		int m = pop();
		visited[m] = 1;
		printf("%d 방문\n", m);
		node* cur = graph[m];
		while (cur) {
			if (isInStack(cur->vtx) == 0 && visited[cur->vtx] == 0) {
				push(cur->vtx);
			}
			cur = cur->next;
		}
	}
}

// BFS를 위한 queue 구현
int queue_bfs[NUM_VTX];
int front = 0;
int rear = 0;
void enqueue(int v) {
	if (front == (rear + 1) % NUM_VTX) {
		return;
	}
	queue_bfs[rear] = v;
	rear = (rear + 1) % NUM_VTX;
	return;
}
int dequeue() {
	if (front == rear) {
		return -999;
	}
	int rtn = queue_bfs[front];
	front = (front + 1) % NUM_VTX;
	return rtn;
}
int isInQueue(int v) {
	int cur = front;
	while (cur != rear) {
		if (queue_bfs[cur] == v) {
			return 1;
		}
		cur = (cur + 1) % NUM_VTX;
	}
	return 0;
}

void do_BFS(int v) {
	int visited[NUM_VTX] = { 0, };
	enqueue(v);
	while (front != rear) {
		int m = dequeue();
		visited[m] = 1;
		printf("%d 방문\n", m);
		node* cur = graph[m];
		while (cur) {
			if (!visited[cur->vtx] && !isInQueue(cur->vtx)) {
				enqueue(cur->vtx);
			}
			cur = cur->next;
		}
	}
}

int isTherePath(int v1, int v2) {

}

//int graph[NUM_VTX][NUM_VTX];
//
//void addEdge(int v1, int v2) {
//	graph[v1][v2] = 1;
//	graph[v2][v1] = 1;
//	return;
//}
//
//int isThereEdge(int v1, int v2) {
//	return graph[v1][v2];
//}

int main() {

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 5);
	addEdge(4, 5);

	do_DFS(0);
	printf("\n\n");
	do_BFS(0);

	return 0;
}