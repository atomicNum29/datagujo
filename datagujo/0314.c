#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3�� 13�� ���� Chapter 4
// 
// stack
// LIFO Last In First Out
// 
// push ���ÿ� ����
// pop  ���ÿ��� ����

// 
// ������ �����ϴ� stack�� �����غ���.
//

#define STACK_SZ 10 // 10�� ������ push�� �� �ִ� stack

int stack[STACK_SZ];
int top = -1; // ���� stack�� ����� index

// stack�� full���� �˻�
// 1 �Ǵ� 0 ��ȯ
int isFull(void) {
	return (top == (STACK_SZ - 1));
}
// stack�� ��� �ִ� �� Ȯ��
// 1 �Ǵ� 0 ��ȯ
int isEmpty(void) {
	return (top == -1);
}

void push(int _v) {

	if (isFull()) { // push �Ұ���
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
		return -999; // stack�� ����ٴ� ���� -999
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