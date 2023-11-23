#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int job_num;
	char grade;
}element;

typedef struct node
{
	element qdata;
	struct node* next;
}QueueNode;


// ���۰� ���� ����Ű�� ������
QueueNode* rear = NULL, * front = NULL;
void addqlist(element item);
element deleteqlist();
void printlist();

void main()
{
	int i, job_num, out, gradeA = 0;
	element tmp;

	// ������ �߰� & ���
	printf("���� �۾��� �۾� ����? : ");
	scanf("%d", &job_num);

	printf("�۾� ��ȣ�� �۾� ���� �Է� : \n");
	for (i = 0; i < job_num; i++)
	{
		scanf("%d %c", &tmp.job_num, &tmp.grade);
		addqlist(tmp);
	}
	printf("\n ���� ť ���� ������ = \n");
	printlist();

	// ������ ���� & �߰� & �ٽ� ���
	printf("\n 1�� ���� �� ���� ���� �׽�Ʈ\n");
	tmp = deleteqlist();	// �� ���� ��� ������ -> ������ ��带 tmp�� ����
	addqlist(tmp);			// �޾Ƴ��Ҵ� tmp�� ť�� ���� �ٽ� �߰�
	printlist();

	// A����� ��常 ǥ��
	printf("A����� ��ǰ��ȣ = ");
	for (i = 0; i < job_num; i++)
	{
		tmp = deleteqlist();	// ť�� front �����͸� 1���� ���� & tmp�� �޴´�.
		if (tmp.grade == 'A')	// ���� tmp�� A����� ��� : ȭ�鿡 ��� & gradeA������ +1  
		{
			printf("%d\t", tmp.job_num);
			gradeA++;
		}
		else // ���� tmp�� A����� �ƴ� ��� : ť�� �� �ڿ� �ٽ� �߰� 
		{
			addqlist(tmp);
		}
	}	// ���������, ť �ȿ��� 'A����� �ƴ� ������'�� ���� �ȴ�. 

	printf("\nA����� ��ǰ�� %d�� �Դϴ�. \n", gradeA);
	printf("%d���� ��� A ���� �� ť ���� ������ = \n", gradeA);
	printlist();	// ������ ���
}

/* ������ �߰� �Լ� */
void addqlist(element item)
{
	// �� ���� ��� �����
	QueueNode* inode;
	inode = (QueueNode*)malloc(sizeof(QueueNode));
	// ���� ��忡 �� �Է�
	inode->qdata = item;	
	inode->next = NULL;

	// ť�� �ƹ� �����͵� ���� �� : front�� rear��, �� ��带 ����
	if (front == NULL)
	{
		front = rear = inode;
	}
	else // �ƴ� ��� : rear(�� �ڸ� ����Ű�� ������)�� ���� �� ��带 ���̰�, rear�� �� ���� ����. 
	{
		rear->next = inode;
		rear = inode;
	}
}

/* ������ ���� �Լ� */
element deleteqlist()
{
	element item;

	if (front == NULL)	// ť�� �� ���
	{
		printf("Queue is Empty");
		exit(1);
	}
	else // �ƴ� ��� : ������ front(�� ���� ����Ű�� ������)�� �����͸� item�� ������ѵΰ�, front�� ���� ���� ����. 
	{
		item = front->qdata;
		front = front->next;
		return item;	// ������ѵξ��� ��带 ��ȯ�Ѵ�.
	}
}

/* ������ ��� �Լ� */
void printlist()
{
	QueueNode* q = front;	// front(�� �� ���) ���� ���
	while (q != NULL)	// front�� null�� ���ö����� ���� ���� �̵���Ŵ 
	{
		printf("%d\t%c\n", q->qdata.job_num, q->qdata.grade);
		q = q->next;
	}
}