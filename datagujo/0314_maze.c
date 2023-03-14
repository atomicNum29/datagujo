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
#define STACK_SIZE (MAZE_SIZE*MAZE_SIZE)

typedef struct {
	int r;
	int c;
} LOC;

LOC stack[STACK_SIZE];
int top = -1;

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
	printf("\n");
}

int isFull(void) {
	return (top == (STACK_SIZE - 1));
}
int isEmpty(void) {
	return (top == -1);
}

// ��ǥ�� �ް�, �� ���鸸 stack�� push.
// ���� 'x' �Ǵ� '0'�� �� ���̴�. ���� ��ǥ�� ������� �Ѵ�.
void push(int _r, int _c) {
	// ���� ��ǥ �Ÿ�
	if ((_r < 0) || (_c < 0)) {
		return;
	}
	// �� ���� �ƴ� �� �Ÿ�
	if (maze[_r][_c] != '0' && maze[_r][_c] != 'x') {
		return;
	}
	// stack full �˻�
	if (isFull()) {
		return;
	}

	LOC temp = { _r, _c };
	top++;
	stack[top] = temp;
	return;
}

LOC pop(void) {
	// if error
	if (isEmpty()) { // stack�� �����
		return ((LOC) { -1, -1 });
	}
	LOC result = stack[top];
	top--;
	return result;
}

int main(void) {

	LOC cur = { 1, 0 }; // ���� ��ġ

	while (1) {

		// Ż�� ����: 'x'�� �����ϸ� ��
		if (maze[cur.r][cur.c] == 'x') {
			printf("�� ã��\n");
			return 0;
		}

		// �Դٰ� ǥ��
		maze[cur.r][cur.c] = '.';

		// ���� Ȯ��
		printMaze();

		// ���� ��ġ���� �� �� �ִ� ���� ��� stack��.
		push(cur.r - 1, cur.c);
		push(cur.r + 1, cur.c);
		push(cur.r, cur.c - 1);
		push(cur.r, cur.c + 1);

		// �� ������ �̵�
		cur = pop();

		// ������ ����ٸ�, �����!!
		if ((cur.r == -1) && (cur.c == -1)) {
			printf("�� ����\n");
			return 0;
		}
	}

	return 0;
}