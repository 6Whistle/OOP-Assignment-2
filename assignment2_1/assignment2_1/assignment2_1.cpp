#include <iostream>
#include <ctime>

using namespace std;

void Printarr(int*);			//array 출력 함수
void Sortarr(int*);			//array 순차 정렬 함수
void Change(int&, int&);			//2개의 값을 서로 바꾸는 함수

int main(void)
{
	srand((unsigned)time(NULL));

	int* row[4];
	int* array_2D = new int[20];
	if (array_2D == NULL)
	{
		cout << "동적 할당 오류" << endl;
		return -1;
	}
	for (int i = 0; i < 20; i++)			//배열에 랜덤한 값 할당
	{
		array_2D[i] = rand() % 20;

	}

	Printarr(array_2D);		//array 출력

	for (int i = 0; i < 20; i++)
	{
		if (i % 5 == 0)
		{
			row[i / 5] = array_2D + i;
			Sortarr(row[i / 5]);					// 각 행렬 순차정렬
		}

	}

	Printarr(array_2D);

	delete[] array_2D;


	return 0;

}


//배열 출력 함수
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

//순차정렬 함수
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

//두 변수의 값을 바꾸는 함수
void Change(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;

	return;
}