#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3월 13일 복습 Chapter 4
// 
// stack
// LIFO Last In First Out
// 
// push 스택에 저장
// pop  스택에서 꺼냄

// 
// 정수를 저장하는 stack을 구현해보자.
//

#define STACK_SZ 10 // 10개 까지만 push할 수 있는 stack

int stack[STACK_SZ];
int top = -1; // 현재 stack의 꼭대기 index

// stack이 full인지 검사
// 1 또는 0 반환
int isFull(void) {
	return (top == (STACK_SZ - 1));
}
// stack이 비어 있는 지 확인
// 1 또는 0 반환
int isEmpty(void) {
	return (top == -1);
}

void push(int _v) {

	if (isFull()) { // push 불가능
		printf("Error, stack full\n");
		return;
	}

	top++;
	stack[top] = _v;

	return;
}

int pop(void) {

	if (isEmpty()) {
		printf("Error, stack empty");
		return -999; // stack이 비었다는 뜻의 -999
	}

	int result = stack[top];
	top--;
	return result;
}

int main() {

	push(4);
	push(5);
	push(6);
	push(7);

	pop();
	printf("%d\n", pop());

	return 0;
}