#define _CRT_SECURE_NO_WARNINGS

//deque 덱
// 
// double ended queue
// 
// 
//

#include <stdio.h>

#define QUEUE_SIZE 10 // 큐의 배열 크기. 10-1만큼 데이터를 저장 가능.
int queue[QUEUE_SIZE]; // 큐의 본체 배열.
int front = 0; // 위치 변수.
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
	rear = (rear + 1) % QUEUE_SIZE; // 순환을 위한 나머지 연산.
	return;
}

int dequeue(void) {

	if (isEmpty()) {
		printf("error: queue empty\n");
		return -999; // -999 is error code.
	}

	int result = queue[front];
	front = (front + 1) % QUEUE_SIZE; // 순환을 위한 나머지 연산.
	return result;
}

// 위까지는 그냥 queue
// 아래는 deque이 되기 위한 두가지 함수

// 1. add to front
// front를 -1하고, 그 위치에 enqueue한다. 
// 단, 제일 먼저 full인지 체크.
void add_to_front(int _v) {

	if (isFull()) {
		printf("error: queue full\n");
		return;
	}

	front = (front + QUEUE_SIZE - 1) % QUEUE_SIZE; // 순환을 위한 트릭.
	queue[front] = _v;
	return;
}

// 2. delete from rear
int del_from_rear() {

	if (isEmpty()) {
		printf("error: queue empty\n");
		return -999; // -999 is error code
	}

	rear = (rear + QUEUE_SIZE - 1) % QUEUE_SIZE; // 순환을 위한 트릭.
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