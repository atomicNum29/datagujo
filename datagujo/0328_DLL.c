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

// _v�� �����ϰ� �ִ� ��� ����
struct node* createNode(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->prev = _new->next = NULL;
	return _new;
}

// _v���� ������ ��带 �� �ڿ� �߰�
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

// _t ���� ������ ����� �ּ� ��ȯ
// ���� �ش� ��尡 ������ NULL ��ȯ
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

// _v�� ��带 _t�� ��� �ڿ� �߰�
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

// _t ��带 ����
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

// ����Ʈ ���
void displayDLL(void) {

	struct node* spear = head;
	while (spear) {
		printf("%d ", spear->data);
		spear = spear->next;
	}
	printf("\n");
	return;
}

// ���� ���
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