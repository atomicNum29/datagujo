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
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
// stack의 top, queue의 front와 rear, linked list의 head.

// SLL의 끝에 _v를 추가한다.
void addToSLL(int _v) {

	// _v 저장 노드 생성
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = NULL; // 신규는 뒤가 없음.

	// SLL이 비어있었다면 _new는 head가 됨.
	if (head == NULL) {
		head = _new;
		return;
	}

	// 비어있지 않다면 기존 SLL에서 맨 끝을 찾고
	struct node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// 그 뒤에 _new를 이어준다.
	temp->next = _new;

	return;
}

// _v를 저장한 노드를 맨 앞에 추가.
void addToFront(int _v) {

	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = NULL;

	// 아무것도 없을 때
	if (head == NULL) {
		head = _new;
		return;
	}
	// 이미 뭔가 있을 때
	_new->next = head; // 새친구가 먼저 접근하기.
	head = _new;
	return;
}

void displaySLL(void) {
	
	struct node* temp = head;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

// 리스트의 크기(노드 개수) 반환
int countSLL(void) {
	struct node* temp = head;
	int cnt = 0;
	while (temp) {
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

// _v 값을 저장한 노드의 주소 반환
// 만약 해당 노드가 없으면 NULL 반환
struct node* findSLL(int _v) {

	struct node* temp = head;
	
	while (temp) {
	
		if (temp->data == _v) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

// _findv값을 가진 노드를 찾아서 그 뒤에 _addv 노드를 추가.
void insertInto(int _findv, int _addv) {

	struct node* target = findSLL(_findv);
	if (target == NULL) {
		return;
	}

	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _addv;
	_new->next = NULL; // 이 부분은 노드를 생성하고 초기화 하는 구역이다.
	// 각 구역에서 하는 일을 확실히 구분하며, 
	// 해당 구역에서 하는 일에만 충실하게 작성하는 것이 좋다.

	_new->next = target->next;
	target->next = _new;
	return;
}

int delFromFront(void) {

	if (head == NULL) {
		return -999; // error code
	}

	// 목표물 포착
	struct node* spear = head;
	// 주민 대피
	head = head->next;
	// 인질 구출
	int rtn = spear->data;
	// 목표물 파괴
	free(spear);
	// 인질 귀가
	return rtn;
}

int delFromLast(void) {

	if (head == NULL) { // 비었을 때
		return -999; // error code
	}

	if (head->next == NULL) { // 노드가 한 개일때
		int rtn = head->data;
		free(head);
		head = NULL;
		return rtn;
	}

	struct node* spear = head;
	while (spear->next->next) {
		spear = spear->next;
	}
	int rtn = spear->next->data;
	free(spear->next);
	spear->next = NULL;
	return rtn;
}

// _v를 저장한 노드를 삭제
void delFromSLL(int _v) {

	struct node* spear = findSLL(_v);

	if (spear == NULL) {
		return;
	}
	// 삭제 노드의 앞이 head인 경우
	if (head == spear) {
		head = spear->next;
		free(spear);
		return;
	}
	// 삭제 노드의 앞이 노드인 경우
	struct node* prev = head;
	while (prev->next != spear) {
		prev = prev->next;
	}
	prev->next = spear->next;
	free(spear);

	return;
}

// SLL의 모든 노드를 삭제한다.
void destroySLL(void) {
	
	struct node* spear = head;

	while (head) {
		head = head->next;
		free(spear);
		spear = head;
	}
	return;
}

int main() {

	addToSLL(10);
	addToSLL(20);
	addToSLL(30);

	addToFront(90);
	addToFront(80);

	printf("앞에서 삭제한 노드의 data: %d\n", delFromFront());
	printf("뒤에서 삭제한 노드의 data: %d\n", delFromLast());

	delFromSLL(10);

	displaySLL();

	printf("size of SLL: %d\n", countSLL());

	printf("20을 저장한 노드의 주소: %p\n", findSLL(20));

	destroySLL();

	//* addToFront 맨 앞 노드 추가
	//* delFromLast 맨 뒤 노드 제거
	//* delFromFront 맨 앞 노드 제거
	//* insertInto 특정 노드 뒤에 추가
	// delFromSLL 특정 원소 삭제
	//* destroySLL 리스트 전체 삭제
	//* countSLL 노드 수 세기
	//* findSLL 특정 원소의 인덱스 찾기
	//

	return 0;
}