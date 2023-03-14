#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// 미로 표기법
// 2차원 배열, char
// '1'이 저장돼있으면 벽
// '0'이면 길
//

// 미로의 크기
#define MAZE_SIZE 6

typedef struct {
	int r;
	int c;
} LOC;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'}, // Entrance
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'}, // eXit
	{'1', '1', '1', '1', '1', '1'}
};

void printMaze(void) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	printMaze();
	return 0;
}