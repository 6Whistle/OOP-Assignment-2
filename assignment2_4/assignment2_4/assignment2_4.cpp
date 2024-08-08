#include <iostream>
using namespace std;

void MakeMatrix(int(*)[9]);		//�迭�� �� �Ҵ��ϴ� �Լ�
void PrintMatrix(int(*)[9]);		//�迭 ��� �Լ�
void MultiMatrix(int(*)[9], int(*)[9], int, int, int);		//3*3��� �� �Լ�

int main(void)
{

	int matrix[9][9];			//���� 9*9 �迭
	int aftermatrix[9][9] = { {0} };		//����� 9*9�迭

	MakeMatrix(matrix);

	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++, count++)
			{
				cout << "N = " << count << endl;
				MultiMatrix(matrix, aftermatrix, 3 * (i % 3), 3 * k, 3 * (j % 3));		//3*3 ��� ó�� ��ġ�� (3*(i%3), 3*k)�� (3*k, 3*(j%3)) ��� ���� ��İ� �Լ��� ���Ͽ� (3*(i%3), 3*(j%3)) ��� ��ġ�� ����
				PrintMatrix(aftermatrix);
			}
		}
	}

	return 0;
}

//�迭�� 0~80 �� �Ҵ��ϴ� �Լ�
void MakeMatrix(int(*matrix)[9])
{
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			matrix[i][j] = count;
			count++;
		}
	}

	return;
}

//�迭 ��� �Լ�
void PrintMatrix(int(*matrix)[9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << endl;

	return;
}

//3*3 ��� �� �Լ�
void MultiMatrix(int(*matrix)[9], int(*resultmatrix)[9], int ax, int ay_and_bx, int by)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				resultmatrix[ax + i][by + j] += matrix[ax + (i % 3)][ay_and_bx + k] * matrix[ay_and_bx + k][by + (j % 3)];		//(ax+i,by+j)��ġ�� (ax + (i % 3),ay + k)�� ���� (bx + k,by+ (j % 3)�� ���� ����
			}
		}
	}
	return;
}