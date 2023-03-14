#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// �̷� ǥ���
// 2���� �迭, char
// '1'�� ����������� ��
// '0'�̸� ��
//

// �̷��� ũ��
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