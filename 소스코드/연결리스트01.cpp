#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeList* nodeListPtr;

/*
 * 노드를 구성할 구조체 :
 *	int 데이터 1개, 다음 노드 주소값 포인터 1개로 구성
 */
struct nodeList {
	int data;
	nodeListPtr next;

};

// 프로토타입
void addNode(nodeListPtr node, int data);

int main() {

	nodeListPtr head, ptr;

	/*
	 * i: 반복제어 변수
	 * n: 데이터를 입력할 횟수
	 */
	int i, n = 3;

	/*
	 * 노드의 헤더 포인터
	 *  선형 연결리스트에 접근하기 위해서는 
	 *	헤더 노드의 주소가 필수 불가결하다. 
	 */
	head = (nodeListPtr)malloc(sizeof(struct nodeList));

	head->data = 10;
	head->next = NULL;

	/*
	 * 데이터 입력 부분 : n번 만큼 반복함
	 *  1. 데이터를 tmp에 임시로 저장
	 *	2. 새로운 노드를 생성하여 tmp의 값을 복사
	 */
	for (i = 0; i < n; i++) {
		printf("정수 입력 : ");
		int tmp;
		scanf("%d", &tmp);
		/*
		 * 새 노드를 생성하는 함수
		 */
		addNode(head, tmp);
	}
		

	ptr = head;

	// 헤더부터 끝까지 노드를 순회하며 데이터를 콘솔에 출력
	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}

}

/*
 * 새 노드를 생성하는 함수
 *  0. 헤더 노드의 주소가 필요하다, 노드에 저장할 데이터도 인자로 받음
 *  1. 헤더부터 시작하여 마지막 노드까지 이동
 *  2. 마지막 노드의 '꼬리'부분에 새로운 노드를 생성
 */
void addNode(nodeListPtr node, int data) {
	nodeListPtr newNode;

	while (node->next != NULL)
		node = node->next;

	newNode = (nodeListPtr)malloc(sizeof(struct nodeList));
	newNode->data = data;
	newNode->next = NULL;
	node->next = newNode;
}