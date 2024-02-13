#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAP_SZ 10
#define SZ (MAP_SZ*MAP_SZ)

int map[MAP_SZ][MAP_SZ] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int graph[SZ][SZ] = { 0, };

void addEdge(int v1, int v2) {
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
	return;
}

struct rc {
	int r;
	int c;
};

int rc2idx (int r, int c) {
	return (r * MAP_SZ + c);
}
struct rc idx2rc(int idx) {
	struct rc res = { idx / MAP_SZ, idx % MAP_SZ };
	return res;
}
void initGraph() {

	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {
			if (map[i][j] == 1) {
				continue;
			}
			if (i + 1 < MAP_SZ && map[i + 1][j] == 0) {
				addEdge(rc2idx(i, j), rc2idx(i + 1, j));
			}
			if (j + 1 < MAP_SZ && map[i][j + 1] == 0) {
				addEdge(rc2idx(i, j), rc2idx(i, j + 1));
			}
		}
	}
	return;
}

struct dij {
	int dist;
	int prev;
	int done;
};
struct dij dtable[SZ];
void initDTable(int sv) {
	for (int i = 0; i < SZ; i++) {
		if (i == sv) {
			dtable[i].dist = 0;
			dtable[i].prev = -1;
			dtable[i].done = 1;
		}
		else if (graph[sv][i]) {
			dtable[i].dist = graph[sv][i];
			dtable[i].prev = sv;
			dtable[i].done = 0;
		}
		else {
			dtable[i].dist = 99999;
			dtable[i].prev = -1;
			dtable[i].done = 0;
		}
	}
	return;
}

int findMinDistVtx() {
	int res = -1;
	int minDist = 99999;
	for (int i = 0; i < SZ; i++) {
		if (dtable[i].done == 0 && minDist > dtable[i].dist) {
			res = i;
			minDist = dtable[i].dist;
		}
	}
	return res;
}

void do_dijkstra(int sv, int tv) {
	initDTable(sv);
	int cur = findMinDistVtx();
	while (cur != -1) {
		dtable[cur].done = 1;
		if (tv == cur) {
			break;
		}

		for (int i = 0; i < SZ; i++) {
			if (graph[cur][i] && dtable[i].done == 0) {
				if (dtable[cur].dist + graph[cur][i] < dtable[i].dist) {
					dtable[i].dist = dtable[cur].dist + graph[cur][i];
					dtable[i].prev = cur;
				}
			}
		}
		cur = findMinDistVtx();
	}
	return;
}

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

	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

	initGraph();
	int v1 = rc2idx(r1, c1);
	int v2 = rc2idx(r2, c2);
	do_dijkstra(v1, v2);

	struct rc cur_rc = idx2rc(v1);
	map[cur_rc.r][cur_rc.c] = 8;
	int cur = v2;
	while (cur != v1) {
		if (cur == -1) {
			printf("±æ ¾øÀ½\n");
			return 0;
		}
		struct rc cur_rc = idx2rc(cur);
		map[cur_rc.r][cur_rc.c] = 8;
		cur = dtable[cur].prev;
	}

	printMap();

	return 0;
}