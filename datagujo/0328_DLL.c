#define _CRT_SECURE_NO_WARNINGS

//
// doubly linked list
// next, prev
// head
//

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head = NULL;

// _v를 저장하고 있는 노드 생성
struct node* createNode(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->prev = _new->next = NULL;
	return _new;
}

// _v값을 저장한 노드를 맨 뒤에 추가
void addToDLL(int _v) {
	
	struct node* _new = createNode(_v);

	if (head == NULL) {
		head = _new;
		return;
	}

	struct node* spear = head;
	while (spear->next) {
		spear = spear->next;
	}
	_new->prev = spear;
	spear->next = _new;
	return;
}

// _t 값을 저장한 노드의 주소 반환
// 만약 해당 노드가 없으면 NULL 반환
struct node* findDLL(int _t) {

	struct node* spear = head;

	while (spear) {

		if (spear->data == _t) {
			return spear;
		}
		spear = spear->next;
	}

	return NULL;
}

// _v의 노드를 _t의 노드 뒤에 추가
void insertIntoDLL(int _t, int _v) {

	struct node* spear = findDLL(_t);
	if (spear == NULL) {
		return;
	}

	struct node* _new = createNode(_v);
	_new->next = spear->next;
	_new->prev = spear;
	spear->next = _new;
	if (_new->next) {
		_new->next->prev = _new;
	}
	return;
}

// _t 노드를 제거
void delFromDLL(int _t) {

	struct node* spear = findDLL(_t);
	if (spear == NULL) {
		return;
	}

	if (spear->prev) {
		spear->prev->next = spear->next;
	}
	else {
		head = spear->next;
	}

	if (spear->next) {
		spear->next->prev = spear->prev;
	}

	free(spear);

	return;
}

// 리스트 출력
void displayDLL(void) {

	struct node* spear = head;
	while (spear) {
		printf("%d ", spear->data);
		spear = spear->next;
	}
	printf("\n");
	return;
}

// 역순 출력
void displayReverseDLL(void) {

	if (head == NULL) {
		return;
	}

	struct node* spear = head;
	while (spear->next) {
		spear = spear->next;
	}

	while (spear) {
		printf("%d ", spear->data);
		spear = spear->prev;
	}
	printf("\n");
	return;
}


int main() {

	addToDLL(10);
	addToDLL(20);
	addToDLL(30);

	insertIntoDLL(20, 40);

	delFromDLL(20);

	displayDLL();
	displayReverseDLL();

	return 0;
}