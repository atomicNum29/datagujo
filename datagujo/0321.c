#define _CRT_SECURE_NO_WARNINGS

// Queue (ť)
// 
// FIFO: First In First Out
// rear -> front
// 
// enqueue (enter queue)
// dequeue (depart from queue)
//
 
// ����
// queue�� stackó�� �迭�� ����Ѵ�.
// front, rear ť���� ��ġ�� ��Ÿ���� ����
// �� ��ť�� ���� �ִ� ��ġ, ��ť�� ��ġ�� ��Ÿ����.
// 
// circular queue
// �Ϲ����� ����� ��ť ��, �����͸� �� ĭ�� ������ ���.
// �̰��� ��ȿ������.
// 
// queue�� isEmpty�� isFull�� ����.
// if (front == rear) than empty
// if (front == rear + 1) than full
// 
// �� ĭ�� ��� ���� �����Ѵ�.
// �ִ� ���� �뷮�� N - 1
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

int main() {

	enqueue(4);
	enqueue(5);
	enqueue(7);

	while (!isEmpty()) {
		printf("%d\n", dequeue());
	}

	return 0;
}