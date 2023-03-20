#define _CRT_SECURE_NO_WARNINGS

//
// infix���� postfix�� 
// 
// ���� ������ �ٲ��� �ʴ´�..
// �����ڴ�?
// 
// ���ʺ��� �дٰ�...
// ���ڰ� ������ �״�� ���
// �����ڸ�
// * �⺻������ push
// * ��, �ڽź��� ��������� ���� ���� ������.
//   -> �ƴϸ� ��������� ���� ���� pop �ϰ� push
// * ��ȣ�� ó������. ���� ��ȣ�� �ݴ� ��ȣ.
//   -> ���� ��ȣ�� ������ push
//   -> ���� ��ȣ�� �켱������ �������� ���.
//    --> � �ٸ� �����ڰ� ������ ���� �ö� �� �ִ�.
//   -> �ݴ� ��ȣ�� ������, ���� ��ȣ�� �ϳ� ���� ������ pop�ϸ鼭 ������ ���
//

#include <stdio.h>

#define STACK_SIZE 20

char stack[STACK_SIZE]; // ��ȣ ����� stack
int top = -1;

int isFull() {
	return (top == (STACK_SIZE - 1));
}

int isEmpty() {
	return (top == -1);
}

void push(char _v) {
	if (isFull()) {
		printf("error: stack full\n");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}

char pop() {
	if (isEmpty()) {
		printf("error: stack empty\n");
		return '\0'; // '\0' is error code.
	}
	char result = stack[top];
	top--;
	return result;
}

int amIHigher(char _c) {

	if (stack[top] == '(') {
		return 1;
	}
	else if (_c == '*' || _c == '/') {
		if (stack[top] == '+' || stack[top] == '-') {
			return 1;
		}
	}

	return 0;
}

// ����
// ���ڴ� �� �ڸ�
// ���� ����
int main() {

	char infix_expr[] = "1*(2+3)";
	int idx = 0;

	while (infix_expr[idx] != '\0') {

		char _c = infix_expr[idx];

		if (_c >= '0' && _c <= '9') { // ���ڸ� ���
			printf("%c", _c);
		}
		else { // ������ �Ǵ� ���� ��ȣ �Ǵ� �ݴ� ��ȣ
			if (_c == '(') { // ���� ��ȣ�� push
				push(_c);
			}
			else if (_c == ')') { // �ݴ� ��ȣ�� pop �ݺ�

				while (1) {
					char _op = pop();
					if (_op == '(') {
						break;
					}
					printf("%c", _op);
				}
			}
			else { // �� ���� ���, �����ڵ��̴�.
				// ��) ������ ����ų�, 
				// ��) top�� '('�� ������ �ٷ� push
				// ��) ������ ������� �ʰ� ��������� ������ �ϴ� ���....
				if (isEmpty()) {
					push(_c);
				}
				else {
					// ������ ������� �ʴٸ� 
					// stack[top]�� _c�� �켱������ ���Ͽ�
					// _c�� ������ �ٷ� push, ��.
					// _c�� ������ pop�ϰ� �ٽ� ��.

					// amIHigher(_c) �켱 ������ �����ִ� �Լ�. top���� ������ 1. �ƴϸ� 0.
					while (1) {
						if (amIHigher(_c)) {
							push(_c);
							break;
						}
						else {
							printf("%c", pop());
						}
					}
				}
			}
		}

		idx++;
	}

	// �� �а� ����, stack�� �� ������ pop�Ͽ� ���
	while (isEmpty() != 1) {
		printf("%c", pop());
	}
	printf("\n");

	return 0;
}