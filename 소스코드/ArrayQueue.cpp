#pragma warning(disable : 4996)
#include <stdio.h>
#define MAX 10

/* �迭 ť 
* 
* ������ �Է��ϰ�, �Է��� ������� �����鼭 A����� �Ǻ��ϴ� ���α׷�
* 
*/

typedef struct {
	int job_num;
	char grade;
}element;

element queue[MAX];
int rear = -1, front = -1;
void addq(element item);
element deleteq();

int main()
{
	int job_num, out, gradeA = 0;
	element tmp;

	// ������ �Է�
	printf("���� �۾��� �۾� ����? : ");
	scanf("%d", &job_num);
	printf("�۾� ��ȣ�� �۾� ���� �Է� : \n");
	for (int i = 0; i < job_num; i++)
	{
		scanf("%d %c", &tmp.job_num, &tmp.grade);
		addq(tmp);
	}
	printf("\n\nfront = %d :: rear = %d\n\n", front, rear);

	// ���� �����ͺ��� 1���� ����  
	for (int i = 0; i < job_num; i++)
	{
		tmp = deleteq();
		if (tmp.grade == 'A')	// A����̸� ���
		{
			printf("%d\t%c\n", tmp.job_num, tmp.grade);
			gradeA++;
		}
	}

	printf("A ��� : %d��\n", gradeA);
	printf("\n\nfront = %d :: rear = %d\n\n", front, rear);
}

void addq(element item)
{
	if (rear == MAX - 1)
		printf("Queue is full\n");
	else
		queue[++rear] = item;	// rear�� 1ĭ �а� �װ��� ������ ����
}

element deleteq()
{
	if (front == rear)
		printf("Queue is empty");
	else
		return queue[++front];	// front�� 1ĭ �а�, �װ��� ������ ��ȯ
}