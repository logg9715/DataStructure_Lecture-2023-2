#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

/*
 * 배열을 포함하는 구조체
 * element라는 속성이 스택 공간
 * key, grade는 데이터를 스택에 넣기 전에 임시로 저장해두는 공간
 */
typedef struct {
	int key;
	char grade;
} element;

int top = -1;

element stack[MAX_STACK_SIZE]; // MaxSize = 10

void push(element data); // 데이터 추가

element pop(); // 데이터 삭제

void main()
{
	element data;
	int i, n, cond = 1;

	while (cond) {
		// 데이터 입력 : key, grade속성에 임시로 저장
		printf("데이터 입력 : ");
		scanf("%d %c", &data.key, &data.grade);
		if (data.key != 0) {
			push(data);
		}

		printf("스택에 데이터를 계속 입력하실래요?(1/0)");
		scanf("%d", &cond);
	}

	printf("스택에서 몇 개의 데이터가 필요하세요? ");
	scanf("%d", &n);

	printf("스택에서 삭제한 데이터 : \n");
	for (i = 0; i < n; i++) {
		data = pop();
		printf("%d\t%c\n", data.key, data.grade);
	}
}

void push(element item)
{
	// 데이터의 끝에 도달한 상태 : top=index9를 보는 상태
	if (top >= MAX_STACK_SIZE - 1)
		printf("Stack is overflow !!!\n");
	else { // 아닌 경우, 데이터 삽입
		top++;
		stack[top] = item;
	}
}

element pop()
{
	// 스택이 비어있는 상태 : top=지하-1층을 보는 상태
	if (top == -1) {
		printf("Stack is empty!!!");
		exit(1);
	}
	/* 현재 top이 보고 있는 데이터를 return하고, 
	* 그 후에 (top -= 1)을 실행한다.
	*/
	else return stack[top--]; 
}