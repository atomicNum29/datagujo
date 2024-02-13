#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAP_SZ 10
#define SZ (MAP_SZ*MAP_SZ)

struct rc {
	int r;
	int c;
};

int map[MAP_SZ][MAP_SZ] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// row와 col을 idx로
int rc2idx(int r, int c) {
	return (r * MAP_SZ + c);
}
// idx를 row와 col로
struct rc idx2rc(int idx) {
	struct rc res = { idx / MAP_SZ, idx % MAP_SZ };
	return res;
}

int graph[SZ][SZ];

void addEdge(int r1, int c1, int r2, int c2) {
	int v1 = rc2idx(r1, c1);
	int v2 = rc2idx(r2, c2);
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
	return;
}

void initGraph() {

	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {
			if (map[i][j] == 1) continue; // 벽, 패스

			if ((j + 1) < MAP_SZ && map[i][j + 1] == 0) {
				addEdge(i, j, i, j + 1);
			}

			if ((i + 1) < MAP_SZ && map[i + 1][j] == 0) {
				addEdge(i, j, i + 1, j);
			}
		}
	}

}

void printGraph() {
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

// 여기부터 Dijkstra
struct dij {
	int prev;
	int dist;
	int done;
};
struct dij dtable[SZ];

void initDTable(int sidx) {
	for (int i = 0; i < SZ; i++) {
		if (sidx == i) {
			dtable[i].dist = 0;
			dtable[i].prev = sidx;
			dtable[i].done = 1;
		}
		else if (graph[sidx][i] > 0) {
			dtable[i].dist = graph[sidx][i];
			dtable[i].prev = sidx;
			dtable[i].done = 0;
		}
		else {
			dtable[i].dist = 99999999;
			dtable[i].prev = -1;
			dtable[i].done = 0;
		}
	}
}

int findMinDistVtx() {
	int minDis = 99999999;
	int minIdx = -1;
	for (int i = 0; i < SZ; i++) {
		if (dtable[i].done == 0 && dtable[i].dist < minDis) {
			minDis = dtable[i].dist;
			minIdx = i;
		}
	}
	return minIdx;
}

void doDijkstra(int r1, int c1, int r2, int c2) {
	int sidx = rc2idx(r1, c1);
	int tidx = rc2idx(r2, c2);
	initDTable(sidx);

	while (1) {
		int res = findMinDistVtx();
		dtable[res].done = 1;
		if (res == tidx) {
			break;
		}

		for (int i = 0; i < SZ; i++) {
			if (dtable[i].done == 0) {
				if (graph[res][i] > 0) {
					if (dtable[i].dist > dtable[res].dist + graph[res][i]) {
						dtable[i].dist = dtable[res].dist + graph[res][i];
						dtable[i].prev = res;
					}
				}
			}
		}
	}
}

void printDTable() {
	printf("idx  prev  dist  done\n");
	for (int i = 0; i < SZ; i++) {
		printf("%3d  %4d  %4d  %4d\n", i, dtable[i].prev, dtable[i].dist, dtable[i].done);
	}
}

// 여기부터 지도에 표시하기 위한
void printMap() {
	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {

	int r1 = 5, c1 = 5;
	int r2 = 9, c2 = 9;

	initGraph();
	//printGraph();

	doDijkstra(r1, c1, r2, c2);
	//printDTable();

	int t = rc2idx(r2, c2);
	int s = rc2idx(r1, c1);
	int temp = t;
	while (1) {
		//printf("%d \n", temp);
		struct rc k = idx2rc(temp);
		map[k.r][k.c] = 8;
		temp = dtable[temp].prev;
		if (temp == s) {
			//printf("%d \n", temp);
			k = idx2rc(temp);
			map[k.r][k.c] = 8;
			break;
		}
	}
	printMap();
	return 0;
}