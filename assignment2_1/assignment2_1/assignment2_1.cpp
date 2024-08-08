#include <iostream>
#include <ctime>

using namespace std;

void Printarr(int*);			//array ��� �Լ�
void Sortarr(int*);			//array ���� ���� �Լ�
void Change(int&, int&);			//2���� ���� ���� �ٲٴ� �Լ�

int main(void)
{
	srand((unsigned)time(NULL));

	int* row[4];
	int* array_2D = new int[20];
	if (array_2D == NULL)
	{
		cout << "���� �Ҵ� ����" << endl;
		return -1;
	}
	for (int i = 0; i < 20; i++)			//�迭�� ������ �� �Ҵ�
	{
		array_2D[i] = rand() % 20;

	}

	Printarr(array_2D);		//array ���

	for (int i = 0; i < 20; i++)
	{
		if (i % 5 == 0)
		{
			row[i / 5] = array_2D + i;
			Sortarr(row[i / 5]);					// �� ��� ��������
		}

	}

	Printarr(array_2D);

	delete[] array_2D;


	return 0;

}


//�迭 ��� �Լ�
void Printarr(int* parr)
{
	for (int i = 0; i < 20; i++)
	{
		if (i % 5 == 0 && i != 0)
			cout << "\n";

		cout << parr[i] << "\t";
	}
	cout << endl;
	cout << endl;

	return;
}

//�������� �Լ�
void Sortarr(int* arr)
{
	for (int i = 0; i < 4; i++)
	{
		int temp = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (*(arr + temp) > *(arr + j))
				temp = j;
		}
		Change(*(arr + i), *(arr + temp));
	}
	return;
}

//�� ������ ���� �ٲٴ� �Լ�
void Change(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;

	return;
}