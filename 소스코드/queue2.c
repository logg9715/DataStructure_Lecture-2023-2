#include <stdio.h>

#define MAX 100


typedef int element;
typedef struct {
	element queue[MAX];
	int front, rear;
}QueueType;

// 초기화
void init(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 확인 
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 확인
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX == q->front);
}

// 삽입
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
	{
		printf("full");
		exit(1);
	}

	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = item;
}

// 삭제
element dequeue(QueueType* q)
{
	if (is_empty(q)) {
		printf("empty");
		exit(1);
	}

	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

// 피크 함수
element peek(QueueType* q)
{
	if (is_empty(q))
	{
		printf("empty");
		exit(1);
	}
	return q->queue[(q->front) % MAX];
}

int main()
{
	QueueType q;

	init(&q);
	printf("front=%d rear=%d\n", q.front, q.rear);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("front=%d rear=%d\n", q.front, q.rear);
}