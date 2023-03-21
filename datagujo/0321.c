#define _CRT_SECURE_NO_WARNINGS

// Queue (큐)
// 
// FIFO: First In First Out
// rear -> front
// 
// enqueue (enter queue)
// dequeue (depart from queue)
//
 
// 구현
// queue도 stack처럼 배열을 사용한다.
// front, rear 큐에서 위치를 나타내는 변수
// 각 디큐할 것이 있는 위치, 인큐할 위치를 나타낸다.
// 
// circular queue
// 일반적인 방식은 디큐 후, 데이터를 한 칸씩 앞으로 당김.
// 이것은 비효율적임.
// 
// queue도 isEmpty와 isFull이 존재.
// if (front == rear) than empty
// if (front == rear + 1) than full
// 
// 한 칸을 비워 둘을 구분한다.
// 최대 저장 용량은 N - 1
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

int main() {

	enqueue(4);
	enqueue(5);
	enqueue(7);

	while (!isEmpty()) {
		printf("%d\n", dequeue());
	}

	return 0;
}