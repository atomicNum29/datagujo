#define _CRT_SECURE_NO_WARNINGS

//연결 리스트
// 
// array의 단점
//  -> 고정된 크기
//  -> 연속된 메모리 공간 필요
//  -> 랜덤 삽입 연산 어려움
//  -> 랜덤 삭제 연산 어려움
// 
// 그래서. 연결 리스트(Linked List)가 나옴.
//   array의 모든 단점을 극복하고,
//   array의 모든 장점을 잃었다..
// 
// 장점
//  1. 필요한만큼 메모리 사용
//  2. 연속되지 않은 메모리고 기워서 사용
//  3, 4. 삽입, 삭제 연산이 용이. 효율적.
// 
// 단점
//  1. 매우 느림
//  2. 구현이 복잡
// 
// 
// linked list 구현
// 
// node: linked list의 개별 요소.
//       데이터를 저장하는 공간과, 
//       자신의 다음을 가리키는 링크가 있다.
//

#include <stdio.h>

struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
// stack의 top, queue의 front와 rear, linked list의 head.

int main() {

	return 0;
}