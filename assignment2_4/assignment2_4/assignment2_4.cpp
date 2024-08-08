#include <iostream>
using namespace std;

void MakeMatrix(int(*)[9]);		//배열에 값 할당하는 함수
void PrintMatrix(int(*)[9]);		//배열 출력 함수
void MultiMatrix(int(*)[9], int(*)[9], int, int, int);		//3*3행렬 곱 함수

int main(void)
{

	int matrix[9][9];			//기존 9*9 배열
	int aftermatrix[9][9] = { {0} };		//출력할 9*9배열

	MakeMatrix(matrix);

	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++, count++)
			{
				cout << "N = " << count << endl;
				MultiMatrix(matrix, aftermatrix, 3 * (i % 3), 3 * k, 3 * (j % 3));		//3*3 행렬 처음 위치가 (3*(i%3), 3*k)과 (3*k, 3*(j%3)) 행렬 둘을 행렬곱 함수로 곱하여 (3*(i%3), 3*(j%3)) 행렬 위치에 저장
				PrintMatrix(aftermatrix);
			}
		}
	}

	return 0;
}

//배열에 0~80 값 할당하는 함수
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

//배열 출력 함수
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

//3*3 행렬 곱 함수
void MultiMatrix(int(*matrix)[9], int(*resultmatrix)[9], int ax, int ay_and_bx, int by)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				resultmatrix[ax + i][by + j] += matrix[ax + (i % 3)][ay_and_bx + k] * matrix[ay_and_bx + k][by + (j % 3)];		//(ax+i,by+j)위치에 (ax + (i % 3),ay + k)의 값과 (bx + k,by+ (j % 3)의 값을 누적
			}
		}
	}
	return;
}