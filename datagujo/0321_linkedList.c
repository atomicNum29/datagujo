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

void displaySLL() {
	
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

int main() {

	addToSLL(10);
	addToSLL(20);
	addToSLL(30);

	displaySLL();

	printf("size of SLL: %d\n", countSLL());

	printf("20�� ������ ����� �ּ�: %p\n", findSLL(20));

	// addToFront �� �� ��� �߰�
	// delFromLast �� �� ��� ����
	// delFromFront �� �� ��� ����
	// insertInto Ư�� ��� �ڿ� �߰�
	// delFromSLL Ư�� ���� ����
	// destroySLL ����Ʈ ��ü ����
	// countSLL ��� �� ����
	// findSLL Ư�� ������ �ε��� ã��
	//

	return 0;
}