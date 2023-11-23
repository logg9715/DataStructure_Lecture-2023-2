#pragma warning(disable : 4996)
#include <stdio.h>
#define MAX 10

/* 배열 큐 
* 
* 성적을 입력하고, 입력한 순서대로 빼내면서 A등급을 판별하는 프로그램
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

	// 데이터 입력
	printf("오늘 작업한 작업 수는? : ");
	scanf("%d", &job_num);
	printf("작업 번호와 작업 상태 입력 : \n");
	for (int i = 0; i < job_num; i++)
	{
		scanf("%d %c", &tmp.job_num, &tmp.grade);
		addq(tmp);
	}
	printf("\n\nfront = %d :: rear = %d\n\n", front, rear);

	// 앞의 데이터부터 1개씩 삭제  
	for (int i = 0; i < job_num; i++)
	{
		tmp = deleteq();
		if (tmp.grade == 'A')	// A등급이면 출력
		{
			printf("%d\t%c\n", tmp.job_num, tmp.grade);
			gradeA++;
		}
	}

	printf("A 등급 : %d개\n", gradeA);
	printf("\n\nfront = %d :: rear = %d\n\n", front, rear);
}

void addq(element item)
{
	if (rear == MAX - 1)
		printf("Queue is full\n");
	else
		queue[++rear] = item;	// rear를 1칸 밀고 그곳에 데이터 삽입
}

element deleteq()
{
	if (front == rear)
		printf("Queue is empty");
	else
		return queue[++front];	// front를 1칸 밀고, 그곳의 데이터 반환
}