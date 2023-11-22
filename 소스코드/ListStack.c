#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// ������ �����ϴ� ����ü
typedef struct {
	int key;
	char grade;
} element;

// ��� ����ü : (������ ����ü)+(�ٸ� ��带 ����Ű�� ������)
typedef struct node {
	element data;
	struct node* next;
} StackNode;

// top ��带 ����Ű�� ������
StackNode* top = NULL;

void pushlist(element data);

element poplist();

int main()
{
	// ���ÿ� ���� �����͸� �ӽ÷� �����ϴ� ���� = ���۰���
	element data;
	int i, n, cond = 1;
	i = 0;

	while (cond) {
		// ������ �Է�
		printf("������ �Է� : ");
		scanf("%d %c", &data.key, &data.grade);
		if (data.key != 0) {
			pushlist(data);	// ����(data)�� �־�״� ������ ���ÿ� �߰�
			i++;	// �����͸� �� �� �Է��ߴ��� �����ϴ� ����
		}

		printf("���ÿ� �����͸� ��� �Է��ϽǷ���?(1/0)");
		scanf("%d", &cond);
	}
	printf("�Է��� �������� ���� : %d \n", i);

	// ������ ����&���
	printf("���ÿ��� ��� �����Ͱ� �ʿ��ϼ��� ? ");
	scanf("%d", &n);
	printf("���ÿ��� ������ ������ : \n");
	for (i = 0; i < n; i++) {
		data = poplist();
		printf("%d \t%c\n", data.key, data.grade);
	}
}

void pushlist(element item)
{
	// �� ���(�� ���) �����ϰ�, �� �����͸� ����
	StackNode* inode;
	inode = (StackNode*)malloc(sizeof(StackNode));
	inode->data = item;

	// �� ����� next(�������)�� top�� ���� �ִ� ���� ����
	inode->next = top;
	// �� ��尡 ���� top�� �ȴ�.
	top = inode;
}

// ������ ����&������ ������ ��ȯ
element poplist()
{
	// ������ �����͸� �ӽ÷� �ְ� return�ϱ� ���� �ӽ� �������(����)
	element item;
	StackNode* dnode; 

	// stack�� ����ִ� ��� : top�� null(����)�� ����Ű�� ���
	if (top == NULL) {
		printf("Stack is empty!!!");
		exit(1);	// ���α׷� ������ ����
	}
	else {	// �ƴ� ��쿡 ������ ����&��ȯ
		// top�� ����Ű�� ������(�հ���)�� �ϳ� �� �����
		dnode = top;
		// ������ �����͸� item(�ӽ� �������)�� �ִ´�. 
		item = dnode->data;
		// top�� �� ĭ ������. = ���� ���� top�� �ű��.
		top = top->next;

		/* 
		* top�� ����Ű�� ���� �޶�����. 
		* ������ top�� ����Ű�� ��常 �޶����� ��, 
		* �޸𸮻󿡼� ���� ���� �����Ѵ�. (�޸� ����)
		* �� �̻� ���� ��带 top���� ����ų ���� ������(�� ĭ ���ȱ� ������)
		* ��������� �������Ҵ� *dnode �����͸� ���� ���� ��带 ������ �Ҵ��� Ǯ���� �� �ִ�.
		*/
		free(dnode);	// heap(��) �������� "���� �Ҵ�"�� �����Ѵ�.

		// item(�ӽ� ���� ����)�� �־�ξ��� "������ ������"�� ������� return�Ѵ�.
		return item;
	}
}