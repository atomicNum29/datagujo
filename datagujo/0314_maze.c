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

// 좌표를 받고, 갈 곳들만 stack에 push.
// 오직 'x' 또는 '0'만 갈 것이다. 또한 좌표는 양수여야 한다.
void push(int _r, int _c) {
	// 음수 좌표 거름
	if ((_r < 0) || (_c < 0)) {
		return;
	}
	// 갈 곳이 아닌 곳 거름
	if (maze[_r][_c] != '0' && maze[_r][_c] != 'x') {
		return;
	}
	// stack full 검사
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
	if (isEmpty()) { // stack이 비었음
		return ((LOC) { -1, -1 });
	}
	LOC result = stack[top];
	top--;
	return result;
}

int main(void) {

	LOC cur = { 1, 0 }; // 시작 위치

	while (1) {

		// 탈출 조건: 'x'에 도착하면 끝
		if (maze[cur.r][cur.c] == 'x') {
			printf("길 찾음\n");
			return 0;
		}

		// 왔다감 표시
		maze[cur.r][cur.c] = '.';

		// 지도 확인
		printMaze();

		// 현재 위치에서 갈 수 있는 곳을 모두 stack에.
		push(cur.r - 1, cur.c);
		push(cur.r + 1, cur.c);
		push(cur.r, cur.c - 1);
		push(cur.r, cur.c + 1);

		// 갈 곳으로 이동
		cur = pop();

		// 스택이 비었다면, 길없음!!
		if ((cur.r == -1) && (cur.c == -1)) {
			printf("길 없음\n");
			return 0;
		}
	}

	return 0;
}