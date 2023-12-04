#include <stdio.h>

#define MAX 100


typedef int element;
typedef struct {
	element queue[MAX];
	int front, rear;
}QueueType;

// �ʱ�ȭ
void init(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� Ȯ�� 
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� Ȯ��
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX == q->front);
}

// ����
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

// ����
element dequeue(QueueType* q)
{
	if (is_empty(q)) {
		printf("empty");
		exit(1);
	}

	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

// ��ũ �Լ�
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