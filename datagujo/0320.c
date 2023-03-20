#define _CRT_SCURE_NO_WARNINGS


// 
// postfix
// 
// infix
// 
// 중위식, 후위식
// 
// postfix는 infix와 다르게, 괄호 없이 연산 순위를 표현할 수 있다.
// 
// (2 + 3) * 5 ---> 2 3 + 5 *
// 
// 앞에서 읽으면서 숫자를 저장하다가
// 연산자를 만나면 바로 앞의 숫자 두 개를 가지고 연산.
// 끝까지 반복
// 
// 사람은 infix로 입력.
//   컴퓨터는 postfix로 변환 후 연산
// 
// 구현을 간단히 하기 위해, 
//   한 자리 숫자 입력
//   사칙연산
//   정수형 계산
//   수식에 공백없이 입력
// 
// stack을 이용해서 구현
//   왼쪽에서부터 읽으면서
//   숫자면 push
//   연산자면 숫자 두 개 pop, 연산, 결과 push
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

// v1, v2를 가지고 op연산한 결과를 반환
int calc_expr(char op, int v1, int v2) {

	switch (op)	{
		case '+':
			return (v1 + v2);
		case '*':
			return (v1 * v2);
		case '-':  
			return (v2 - v1); // 계산 순서에 유의
		case '/':  
			return (v2 / v1);
		default:
			break;
	}
}

int main() {

	char postfix[] = "235*+"; // postfix expression
	int idx = 0; // expression 읽는 위치

	// 한 글자씩 전부 읽음.
	while (postfix[idx] != '\0') {

		char _c = postfix[idx];
		
		//읽은 것이 숫자인 경우
		if (_c >= '0' && _c <= '9') {
			push((int)(_c - '0'));
		}
		else { // 숫자 아니면 연산자가 들어올 것.. 실무에서는 에러 체크를 해야한다!

			// 코드가 복잡해질 것 같을 땐, 함수로 뺀다.
			int v1 = pop();
			int v2 = pop();
			int res = calc_expr(_c, v1, v2);
			push(res);
		}

		idx++;
	}
	
	// 여기에 도달했다면, 모든 계산 후 숫자 하나만 stack에 남는다.
	printf("계산 결과: %d\n", pop());

	return 0;
}