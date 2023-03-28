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

void displayDLL(void) {

	struct node* spear = head;
	while (spear) {
		printf("%d ", spear->data);
		spear = spear->next;
	}
	printf("\n");
	return;
}

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

	displayDLL();
	displayReverseDLL();

	return 0;
}