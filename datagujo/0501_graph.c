#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NUM_VTX 4

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

	addEdge(0, 3);
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);

	return 0;
}