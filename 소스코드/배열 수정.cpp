#include <iostream>
#include <vector>
#define SIZE 5

using namespace std;

void printArr(int arr[]);
void rmElement(int arr[], int size, int index);

int main()
{
	int data[] = { 1,2,3,4,5 };

	printArr(data);

	// �迭�� ���� ����
	int tmp;
	cin >> tmp;
	rmElement(data, SIZE, tmp);

	printArr(data);
}

void printArr(int arr[])
{
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << endl;
}

void rmElement(int arr[], int size, int index)
{
	// exception
	if (index >= SIZE)
	{
		cout << "�߸��� �ε���" << endl;
		return;
	}

	int i;
	for (i = index + 1; i < SIZE; i++)
	{
		arr[i - 1] = arr[i];
	}

	cout << "���ο� ������ �Է� : ";
	cin >> arr[i - 1];
}