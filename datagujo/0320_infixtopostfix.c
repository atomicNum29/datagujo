#define _CRT_SECURE_NO_WARNINGS

//
// infix에서 postfix로 
// 
// 숫자 순서는 바뀌지 않는다..
// 연산자는?
// 
// 왼쪽부터 읽다가...
// 숫자가 나오면 그대로 출력
// 연산자면
// * 기본적으로 push
// * 단, 자신보다 연산순위가 낮은 것이 있으면.
//   -> 아니면 연산순위가 높은 것을 pop 하고서 push
// * 괄호를 처리하자. 여는 괄호와 닫는 괄호.
//   -> 여는 괄호는 무조건 push
//   -> 여는 괄호의 우선순위는 최하위로 취급.
//    --> 어떤 다른 연산자가 오더라도 위에 올라갈 수 있다.
//   -> 닫는 괄호가 나오면, 여는 괄호가 하나 나올 때까지 pop하면서 연산자 출력
//

#include <stdio.h>

#define STACK_SIZE 20

char stack[STACK_SIZE]; // 기호 저장용 stack
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

// 가정
// 숫자는 한 자리
// 공백 없음
int main() {

	char infix_expr[] = "1*(2+3)";
	int idx = 0;

	while (infix_expr[idx] != '\0') {

		char _c = infix_expr[idx];

		if (_c >= '0' && _c <= '9') { // 숫자면 출력
			printf("%c", _c);
		}
		else { // 연산자 또는 여는 괄호 또는 닫는 괄호
			if (_c == '(') { // 여는 괄호면 push
				push(_c);
			}
			else if (_c == ')') { // 닫는 괄호면 pop 반복

				while (1) {
					char _op = pop();
					if (_op == '(') {
						break;
					}
					printf("%c", _op);
				}
			}
			else { // 그 외의 경우, 연산자들이다.
				// 가) 스택이 비었거나, 
				// 나) top에 '('가 있으면 바로 push
				// 다) 스택이 비어있지 않고 연산순위를 따져야 하는 경우....
				if (isEmpty()) {
					push(_c);
				}
				else {
					// 스택이 비어있지 않다면 
					// stack[top]과 _c의 우선순위를 비교하여
					// _c가 높으면 바로 push, 끝.
					// _c가 낮으면 pop하고 다시 비교.

					// amIHigher(_c) 우선 순위를 비교해주는 함수. top보다 높으면 1. 아니면 0.
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

	// 다 읽고 나면, stack이 빌 때까지 pop하여 출력
	while (isEmpty() != 1) {
		printf("%c", pop());
	}
	printf("\n");

	return 0;
}