#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SZ 4

int graph[SZ][SZ];
int floyd_graph[SZ][SZ];

void addEdge(int v1, int v2, int w) {
	graph[v1][v2] = w;
	graph[v2][v1] = w;
	return;
}

int initFloydGraph() {
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (i == j) {
				floyd_graph[i][j] = 0;
			}
			else if (graph[i][j]) {
				floyd_graph[i][j] = graph[i][j];
			}
			else {
				floyd_graph[i][j] = 9999;
			}
		}
	}
}

int main() {

	addEdge(0, 1, 1);
	addEdge(0, 3, 1);
	addEdge(1, 2, 1);

	initFloydGraph();

	for (int k = 0; k < SZ; k++) {
		for (int i = 0; i < SZ; i++) {
			if (k == i) continue;
			for (int j = 0; j < SZ; j++) {
				if (k == j) continue;
				if (floyd_graph[i][j] > floyd_graph[i][k] + floyd_graph[k][j]) {
					floyd_graph[i][j] = floyd_graph[i][k] + floyd_graph[k][j];
				}
			}
		}
	}

	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			printf("%d ", floyd_graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}