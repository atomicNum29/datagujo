#define _CRT_SCURE_NO_WARNINGS


// 
// postfix
// 
// infix
// 
// ������, ������
// 
// postfix�� infix�� �ٸ���, ��ȣ ���� ���� ������ ǥ���� �� �ִ�.
// 
// (2 + 3) * 5 ---> 2 3 + 5 *
// 
// �տ��� �����鼭 ���ڸ� �����ϴٰ�
// �����ڸ� ������ �ٷ� ���� ���� �� ���� ������ ����.
// ������ �ݺ�
// 
// ����� infix�� �Է�.
//   ��ǻ�ʹ� postfix�� ��ȯ �� ����
// 
// ������ ������ �ϱ� ����, 
//   �� �ڸ� ���� �Է�
//   ��Ģ����
//   ������ ���
//   ���Ŀ� ������� �Է�
// 
// stack�� �̿��ؼ� ����
//   ���ʿ������� �����鼭
//   ���ڸ� push
//   �����ڸ� ���� �� �� pop, ����, ��� push
//

#include <stdio.h>

#define STACK_SIZE 20

int stack[STACK_SIZE];
int top = -1;

int isFull() {
	return (top == (STACK_SIZE - 1));
}

int isEmpty() {
	return (top == -1);
}

void push(int _v) {
	if (isFull()) {
		printf("error: stack full\n");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}

int pop() {
	if (isEmpty()) {
		printf("error: stack empty\n");
		return -999; // -999 is error code.
	}
	int result = stack[top];
	top--;
	return result;
}

// v1, v2�� ������ op������ ����� ��ȯ
int calc_expr(char op, int v1, int v2) {

	switch (op)	{
		case '+':
			return (v1 + v2);
		case '*':
			return (v1 * v2);
		case '-':  
			return (v2 - v1); // ��� ������ ����
		case '/':  
			return (v2 / v1);
		default:
			break;
	}
}

int main() {

	char postfix[] = "235*+"; // postfix expression
	int idx = 0; // expression �д� ��ġ

	// �� ���ھ� ���� ����.
	while (postfix[idx] != '\0') {

		char _c = postfix[idx];
		
		//���� ���� ������ ���
		if (_c >= '0' && _c <= '9') {
			push((int)(_c - '0'));
		}
		else { // ���� �ƴϸ� �����ڰ� ���� ��.. �ǹ������� ���� üũ�� �ؾ��Ѵ�!

			// �ڵ尡 �������� �� ���� ��, �Լ��� ����.
			int v1 = pop();
			int v2 = pop();
			int res = calc_expr(_c, v1, v2);
			push(res);
		}

		idx++;
	}
	
	// ���⿡ �����ߴٸ�, ��� ��� �� ���� �ϳ��� stack�� ���´�.
	printf("��� ���: %d\n", pop());

	return 0;
}