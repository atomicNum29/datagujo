#define _CRT_SECURE_NO_WARNINGS

//���� ����Ʈ
// 
// array�� ����
//  -> ������ ũ��
//  -> ���ӵ� �޸� ���� �ʿ�
//  -> ���� ���� ���� �����
//  -> ���� ���� ���� �����
// 
// �׷���. ���� ����Ʈ(Linked List)�� ����.
//   array�� ��� ������ �غ��ϰ�,
//   array�� ��� ������ �Ҿ���..
// 
// ����
//  1. �ʿ��Ѹ�ŭ �޸� ���
//  2. ���ӵ��� ���� �޸𸮰� ����� ���
//  3, 4. ����, ���� ������ ����. ȿ����.
// 
// ����
//  1. �ſ� ����
//  2. ������ ����
// 
// 
// linked list ����
// 
// node: linked list�� ���� ���.
//       �����͸� �����ϴ� ������, 
//       �ڽ��� ������ ����Ű�� ��ũ�� �ִ�.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
// stack�� top, queue�� front�� rear, linked list�� head.

// SLL�� ���� _v�� �߰��Ѵ�.
void addToSLL(int _v) {

	// _v ���� ��� ����
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = NULL; // �űԴ� �ڰ� ����.

	// SLL�� ����־��ٸ� _new�� head�� ��.
	if (head == NULL) {
		head = _new;
		return;
	}

	// ������� �ʴٸ� ���� SLL���� �� ���� ã��
	struct node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// �� �ڿ� _new�� �̾��ش�.
	temp->next = _new;

	return;
}

// _v�� ������ ��带 �� �տ� �߰�.
void addToFront(int _v) {

	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = NULL;

	// �ƹ��͵� ���� ��
	if (head == NULL) {
		head = _new;
		return;
	}
	// �̹� ���� ���� ��
	_new->next = head; // ��ģ���� ���� �����ϱ�.
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

// ����Ʈ�� ũ��(��� ����) ��ȯ
int countSLL(void) {
	struct node* temp = head;
	int cnt = 0;
	while (temp) {
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

// _v ���� ������ ����� �ּ� ��ȯ
// ���� �ش� ��尡 ������ NULL ��ȯ
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

// _findv���� ���� ��带 ã�Ƽ� �� �ڿ� _addv ��带 �߰�.
void insertInto(int _findv, int _addv) {

	struct node* target = findSLL(_findv);
	if (target == NULL) {
		return;
	}

	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _addv;
	_new->next = NULL; // �� �κ��� ��带 �����ϰ� �ʱ�ȭ �ϴ� �����̴�.
	// �� �������� �ϴ� ���� Ȯ���� �����ϸ�, 
	// �ش� �������� �ϴ� �Ͽ��� ����ϰ� �ۼ��ϴ� ���� ����.

	_new->next = target->next;
	target->next = _new;
	return;
}

int delFromFront(void) {

	if (head == NULL) {
		return -999; // error code
	}

	// ��ǥ�� ����
	struct node* spear = head;
	// �ֹ� ����
	head = head->next;
	// ���� ����
	int rtn = spear->data;
	// ��ǥ�� �ı�
	free(spear);
	// ���� �Ͱ�
	return rtn;
}

int delFromLast(void) {

	if (head == NULL) { // ����� ��
		return -999; // error code
	}

	if (head->next == NULL) { // ��尡 �� ���϶�
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

// _v�� ������ ��带 ����
void delFromSLL(int _v) {

	struct node* spear = findSLL(_v);

	if (spear == NULL) {
		return;
	}
	// ���� ����� ���� head�� ���
	if (head == spear) {
		head = spear->next;
		free(spear);
		return;
	}
	// ���� ����� ���� ����� ���
	struct node* prev = head;
	while (prev->next != spear) {
		prev = prev->next;
	}
	prev->next = spear->next;
	free(spear);

	return;
}

// SLL�� ��� ��带 �����Ѵ�.
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

	printf("�տ��� ������ ����� data: %d\n", delFromFront());
	printf("�ڿ��� ������ ����� data: %d\n", delFromLast());

	delFromSLL(10);

	displaySLL();

	printf("size of SLL: %d\n", countSLL());

	printf("20�� ������ ����� �ּ�: %p\n", findSLL(20));

	destroySLL();

	//* addToFront �� �� ��� �߰�
	//* delFromLast �� �� ��� ����
	//* delFromFront �� �� ��� ����
	//* insertInto Ư�� ��� �ڿ� �߰�
	// delFromSLL Ư�� ���� ����
	//* destroySLL ����Ʈ ��ü ����
	//* countSLL ��� �� ����
	//* findSLL Ư�� ������ �ε��� ã��
	//

	return 0;
}