#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SZ 6

void addDEdge(int _sv, int _ev, int g[][SZ]) {
	g[_sv][_ev] = 1;
	return;
}

void initIndegree(int g[][SZ], int ideg[]) {
	
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (g[i][j]) {
				ideg[j] += 1;
			}
		}
	}

	return;
}

// at indegree table, find vertex that is zero indegree
int findZeroIndegreeVtx(int ideg[]) {
	
	for (int i = 0; i < SZ; i++) {
		if (ideg[i] == 0) {
			return i;
		}
	}
	
	return -1; //error or end
}

void topo_sort(int g[][SZ], int ideg[]) {

	while (1) {

		int v = findZeroIndegreeVtx(ideg);
		if (v == -1) {
			return;
		}

		printf("%d \n", v);
		ideg[v] = -1;
		for (int i = 0; i < SZ; i++) {
			if (g[v][i]) {
				ideg[i] -= 1;
			}
		}

	}
	return;
}

int main() {

	int graph[SZ][SZ] = { 0, };
	int indegree[SZ] = { 0, };
	
	addDEdge(0, 1, graph);
	addDEdge(0, 2, graph);
	addDEdge(0, 3, graph);
	addDEdge(1, 4, graph);
	addDEdge(2, 4, graph);
	addDEdge(2, 5, graph);
	addDEdge(3, 5, graph);

	initIndegree(graph, indegree);

	topo_sort(graph, indegree);

	return 0;
}