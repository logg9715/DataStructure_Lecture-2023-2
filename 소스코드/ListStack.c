#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// 데이터 저장하는 구조체
typedef struct {
	int key;
	char grade;
} element;

// 노드 구조체 : (데이터 구조체)+(다른 노드를 가리키는 포인터)
typedef struct node {
	element data;
	struct node* next;
} StackNode;

// top 노드를 가리키는 포인터
StackNode* top = NULL;

void pushlist(element data);

element poplist();

int main()
{
	// 스택에 넣을 데이터를 임시로 저장하는 공간 = 버퍼개념
	element data;
	int i, n, cond = 1;
	i = 0;

	while (cond) {
		// 데이터 입력
		printf("데이터 입력 : ");
		scanf("%d %c", &data.key, &data.grade);
		if (data.key != 0) {
			pushlist(data);	// 버퍼(data)에 넣어뒀던 변수를 스택에 추가
			i++;	// 데이터를 몇 번 입력했는지 저장하는 변수
		}

		printf("스택에 데이터를 계속 입력하실래요?(1/0)");
		scanf("%d", &cond);
	}
	printf("입력한 데이터의 개수 : %d \n", i);

	// 데이터 제거&출력
	printf("스택에서 몇개의 데이터가 필요하세요 ? ");
	scanf("%d", &n);
	printf("스택에서 삭제한 데이터 : \n");
	for (i = 0; i < n; i++) {
		data = poplist();
		printf("%d \t%c\n", data.key, data.grade);
	}
}

void pushlist(element item)
{
	// 빈 노드(새 노드) 생성하고, 새 데이터를 넣음
	StackNode* inode;
	inode = (StackNode*)malloc(sizeof(StackNode));
	inode->data = item;

	// 새 노드의 next(다음노드)를 top이 보고 있는 노드로 지정
	inode->next = top;
	// 새 노드가 이젠 top이 된다.
	top = inode;
}

// 데이터 삭제&삭제한 데이터 반환
element poplist()
{
	// 삭제한 데이터를 임시로 넣고 return하기 위한 임시 저장공간(버퍼)
	element item;
	StackNode* dnode; 

	// stack이 비어있는 경우 : top이 null(지하)를 가리키는 경우
	if (top == NULL) {
		printf("Stack is empty!!!");
		exit(1);	// 프로그램 비정상 종료
	}
	else {	// 아닌 경우에 데이터 삭제&반환
		// top을 가리키는 포인터(손가락)을 하나 더 만든다
		dnode = top;
		// 삭제할 데이터를 item(임시 저장공간)에 넣는다. 
		item = dnode->data;
		// top을 한 칸 내린다. = 다음 노드로 top을 옮긴다.
		top = top->next;

		/* 
		* top이 가리키던 노드는 달라졌다. 
		* 하지만 top이 가리키는 노드만 달라졌을 뿐, 
		* 메모리상에서 아직 노드는 존재한다. (메모리 누수)
		* 더 이상 이전 노드를 top으로 가리킬 수는 없지만(한 칸 내렸기 때문에)
		* 예비용으로 만들어놓았던 *dnode 포인터를 통해 이전 노드를 접근해 할당을 풀어줄 수 있다.
		*/
		free(dnode);	// heap(힙) 영역에서 "동적 할당"을 해제한다.

		// item(임시 저장 공간)에 넣어두었던 "삭제한 데이터"의 백업본을 return한다.
		return item;
	}
}