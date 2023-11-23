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


// 시작과 끝을 가리키는 포인터
QueueNode* rear = NULL, * front = NULL;
void addqlist(element item);
element deleteqlist();
void printlist();

void main()
{
	int i, job_num, out, gradeA = 0;
	element tmp;

	// 데이터 추가 & 출력
	printf("오늘 작업한 작업 수는? : ");
	scanf("%d", &job_num);

	printf("작업 번호와 작업 상태 입력 : \n");
	for (i = 0; i < job_num; i++)
	{
		scanf("%d %c", &tmp.job_num, &tmp.grade);
		addqlist(tmp);
	}
	printf("\n 연결 큐 안의 데이터 = \n");
	printlist();

	// 데이터 삭제 & 추가 & 다시 출력
	printf("\n 1개 삭제 후 삽입 연산 테스트\n");
	tmp = deleteqlist();	// 맨 앞의 노드 삭제됨 -> 삭제한 노드를 tmp로 받음
	addqlist(tmp);			// 받아놓았던 tmp를 큐의 끝에 다시 추가
	printlist();

	// A등급인 노드만 표시
	printf("A등급인 제품번호 = ");
	for (i = 0; i < job_num; i++)
	{
		tmp = deleteqlist();	// 큐의 front 데이터를 1개씩 삭제 & tmp로 받는다.
		if (tmp.grade == 'A')	// 받은 tmp가 A등급인 경우 : 화면에 출력 & gradeA변수에 +1  
		{
			printf("%d\t", tmp.job_num);
			gradeA++;
		}
		else // 받은 tmp가 A등급이 아닌 경우 : 큐의 맨 뒤에 다시 추가 
		{
			addqlist(tmp);
		}
	}	// 결과적으로, 큐 안에는 'A등급이 아닌 데이터'만 남게 된다. 

	printf("\nA등급인 제품은 %d개 입니다. \n", gradeA);
	printf("%d개의 등급 A 삭제 후 큐 안의 데이터 = \n", gradeA);
	printlist();	// 데이터 출력
}

/* 데이터 추가 함수 */
void addqlist(element item)
{
	// 빈 깡통 노드 만들기
	QueueNode* inode;
	inode = (QueueNode*)malloc(sizeof(QueueNode));
	// 깡통 노드에 값 입력
	inode->qdata = item;	
	inode->next = NULL;

	// 큐에 아무 데이터도 없을 때 : front와 rear에, 새 노드를 붙임
	if (front == NULL)
	{
		front = rear = inode;
	}
	else // 아닌 경우 : rear(맨 뒤를 가리키는 포인터)의 끝에 새 노드를 붙이고, rear를 새 노드로 당긴다. 
	{
		rear->next = inode;
		rear = inode;
	}
}

/* 데이터 삭제 함수 */
element deleteqlist()
{
	element item;

	if (front == NULL)	// 큐가 빈 경우
	{
		printf("Queue is Empty");
		exit(1);
	}
	else // 아닌 경우 : 삭제할 front(맨 앞을 가리키는 포인터)의 데이터를 item에 백업시켜두고, front를 다음 노드로 당긴다. 
	{
		item = front->qdata;
		front = front->next;
		return item;	// 백업시켜두었던 노드를 반환한다.
	}
}

/* 데이터 출력 함수 */
void printlist()
{
	QueueNode* q = front;	// front(맨 앞 노드) 부터 출발
	while (q != NULL)	// front가 null이 나올때까지 다음 노드로 이동시킴 
	{
		printf("%d\t%c\n", q->qdata.job_num, q->qdata.grade);
		q = q->next;
	}
}