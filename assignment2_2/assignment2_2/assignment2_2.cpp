#define _CRT_SECURE_NO_WARNINGS				//strcpy 사용을 위한 선언
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int Command(char*);			//명령어를 받는 함수
void Insert(char**, char*, int&);		//단어 삽입 함수
void Find(char**, char*, int);		//단어 탐색 함수
void PrintVoca(char**, int);		//단어 리스트 출력 함수
int Mystrcmp(char*, char*);			//대소문자 구분 없이 문자열을 비교하는 함수

int main(void)
{
	char** list;
	list = new char* [100];			//문자열 리스트 생성


	int num = 0;

	while (true)
	{
		int cmd;
		char words[1024];

		cmd = Command(words);		//명령 함수를 통해 cmd값을 읽어오고 이 값을 토대로 명령 수행
		if (cmd == 1)		//입력이 INSERT인 경우 단어가 100개 미만일 시 문자열 호출
		{
			if (num == 100)
			{
				cout << "is Fulled" << endl;
			}
			else
			{
				*(list + num) = new char[1024];
				Insert(list, words, num);
			}
		}
		else if (cmd == 2)		//입력이 FIND일 경우 탐색 함수 호출
			Find(list, words, num);
		else if (cmd == 0)		//입력이 END일 경우 동적 할당 해제 후 프로그램 종료
		{
			for (int i = 0; i < num + 1; i++)
			{
				delete[] list[i];
			}
			delete[] list;

			return 0;
		}
	}

}

//명령어를 받는 함수
int Command(char* words)
{
	while (true)
	{
		char input[7];
		char name[1024];

		cin >> input;

		char insert[] = "INSERT";
		char find[] = "FIND";
		char end[] = "END";

		if (Mystrcmp(input, insert) == 0)		//입력이 INSERT일 경우 단어를 저장하고 1반환
		{
			cin >> name;
			strcpy(words, name);
			return 1;
		}
		else if (Mystrcmp(input, find) == 0)		//입력이 FIND일 경우 단어를 저장하고 2반환
		{
			cin >> name;
			strcpy(words, name);
			return 2;
		}
		else if (Mystrcmp(input, end) == 0)		//입력이 END일 경우 0 반환
		{
			return 0;
		}

	}
}

//문자 삽입 함수
void Insert(char** list, char* words, int& end)
{
	if (end == 0)		//만약 단어가 아무것도 저장되어있지 않았을 경우
	{
		strcpy(*(list + end), words);

		end++;
		PrintVoca(list, end);
		return;
	}
	for (int i = 0; i < end; i++)		//단어가 1개라도 저장되어있을 경우
	{
		int state = Mystrcmp(words, *(list + i));
		if (state == 0)			//중복 여부 검사
		{
			PrintVoca(list, end);
			delete[] list[end];
			return;
		}
		else if (state == 1)		//중복이 아니고 입력받은 문자가 현재 문자 앞에 위치해있어야 하는 경우
		{
			char copy[1024];
			char temp[1024];

			strcpy(copy, words);
			for (int j = i; j <= end; j++)		//한 칸씩 배열을 미룸
			{
				if (j < end)
				{
					strcpy(temp, *(list + j));
				}
				strcpy(*(list + j), copy);
				strcpy(copy, temp);
			}

			end++;
			PrintVoca(list, end);

			return;
		}
	}
	strcpy(*(list + end), words);
	end++;
	PrintVoca(list, end);


	return;
}

//단어 탐색 함수
void Find(char** list, char* words, int end)
{
	for (int i = 0; i < end; i++)
	{
		int state = Mystrcmp(words, *(list + i));
		if (state == 0)
		{
			cout << i << '.' << *(list + i) << endl;
			return;
		}
	}
	cout << "Not Found" << endl;
	return;
}

//단어 출력 함수
void PrintVoca(char** list, int end)
{
	for (int i = 0; i < end; i++)
	{
		cout << i << '.' << *(list + i) << endl;
	}
	return;
}

//단어를 대소문자 구분 없이 비교하는 함수
int Mystrcmp(char* a, char* b)
{
	for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++)			//두 문자열의 중 가장 짧은 문자열의 길이만큼 비교
	{
		char pa = a[i];
		char pb = b[i];

		if (isupper(a[i]))
			pa += 32;
		if (isupper(b[i]))
			pb += 32;

		if (pa < pb)
			return 1;
		else if (pa > pb)
			return 2;
	}
	if (strlen(a) < strlen(b))			//문자열의 길이 비교
		return 1;
	else if (strlen(a) > strlen(b))
		return 2;
	else
		return 0;
}