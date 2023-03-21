#define _CRT_SECURE_NO_WARNINGS

//deque ��
// 
// double ended queue
// 
// 
//

#include <stdio.h>

#define QUEUE_SIZE 10 // ť�� �迭 ũ��. 10-1��ŭ �����͸� ���� ����.
int queue[QUEUE_SIZE]; // ť�� ��ü �迭.
int front = 0; // ��ġ ����.
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() {
	return (front == ((rear + 1) % QUEUE_SIZE));
}

void enqueue(int _v) {

	if (isFull()) {
		printf("error: queue full\n");
		return;
	}

	queue[rear] = _v;
	rear = (rear + 1) % QUEUE_SIZE; // ��ȯ�� ���� ������ ����.
	return;
}

int dequeue(void) {

	if (isEmpty()) {
		printf("error: queue empty\n");
		return -999; // -999 is error code.
	}

	int result = queue[front];
	front = (front + 1) % QUEUE_SIZE; // ��ȯ�� ���� ������ ����.
	return result;
}

// �������� �׳� queue
// �Ʒ��� deque�� �Ǳ� ���� �ΰ��� �Լ�

// 1. add to front
// front�� -1�ϰ�, �� ��ġ�� enqueue�Ѵ�. 
// ��, ���� ���� full���� üũ.
void add_to_front(int _v) {

	if (isFull()) {
		printf("error: queue full\n");
		return;
	}

	front = (front + QUEUE_SIZE - 1) % QUEUE_SIZE; // ��ȯ�� ���� Ʈ��.
	queue[front] = _v;
	return;
}

// 2. delete from rear
int del_from_rear() {

	if (isEmpty()) {
		printf("error: queue empty\n");
		return -999; // -999 is error code
	}

	rear = (rear + QUEUE_SIZE - 1) % QUEUE_SIZE; // ��ȯ�� ���� Ʈ��.
	return queue[rear];
}

int main() {

	add_to_front(10);
	enqueue(20);
	enqueue(30);
	add_to_front(40);

	while (!isEmpty()) {
		printf("%d ", del_from_rear());
	}

	return 0;
}