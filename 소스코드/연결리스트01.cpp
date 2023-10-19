#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeList* nodeListPtr;

/*
 * ��带 ������ ����ü :
 *	int ������ 1��, ���� ��� �ּҰ� ������ 1���� ����
 */
struct nodeList {
	int data;
	nodeListPtr next;

};

// ������Ÿ��
void addNode(nodeListPtr node, int data);

int main() {

	nodeListPtr head, ptr;

	/*
	 * i: �ݺ����� ����
	 * n: �����͸� �Է��� Ƚ��
	 */
	int i, n = 3;

	/*
	 * ����� ��� ������
	 *  ���� ���Ḯ��Ʈ�� �����ϱ� ���ؼ��� 
	 *	��� ����� �ּҰ� �ʼ� �Ұ����ϴ�. 
	 */
	head = (nodeListPtr)malloc(sizeof(struct nodeList));

	head->data = 10;
	head->next = NULL;

	/*
	 * ������ �Է� �κ� : n�� ��ŭ �ݺ���
	 *  1. �����͸� tmp�� �ӽ÷� ����
	 *	2. ���ο� ��带 �����Ͽ� tmp�� ���� ����
	 */
	for (i = 0; i < n; i++) {
		printf("���� �Է� : ");
		int tmp;
		scanf("%d", &tmp);
		/*
		 * �� ��带 �����ϴ� �Լ�
		 */
		addNode(head, tmp);
	}
		

	ptr = head;

	// ������� ������ ��带 ��ȸ�ϸ� �����͸� �ֿܼ� ���
	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}

}

/*
 * �� ��带 �����ϴ� �Լ�
 *  0. ��� ����� �ּҰ� �ʿ��ϴ�, ��忡 ������ �����͵� ���ڷ� ����
 *  1. ������� �����Ͽ� ������ ������ �̵�
 *  2. ������ ����� '����'�κп� ���ο� ��带 ����
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