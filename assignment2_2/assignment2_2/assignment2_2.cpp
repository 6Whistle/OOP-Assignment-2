#define _CRT_SECURE_NO_WARNINGS				//strcpy ����� ���� ����
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int Command(char*);			//��ɾ �޴� �Լ�
void Insert(char**, char*, int&);		//�ܾ� ���� �Լ�
void Find(char**, char*, int);		//�ܾ� Ž�� �Լ�
void PrintVoca(char**, int);		//�ܾ� ����Ʈ ��� �Լ�
int Mystrcmp(char*, char*);			//��ҹ��� ���� ���� ���ڿ��� ���ϴ� �Լ�

int main(void)
{
	char** list;
	list = new char* [100];			//���ڿ� ����Ʈ ����


	int num = 0;

	while (true)
	{
		int cmd;
		char words[1024];

		cmd = Command(words);		//��� �Լ��� ���� cmd���� �о���� �� ���� ���� ��� ����
		if (cmd == 1)		//�Է��� INSERT�� ��� �ܾ 100�� �̸��� �� ���ڿ� ȣ��
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
		else if (cmd == 2)		//�Է��� FIND�� ��� Ž�� �Լ� ȣ��
			Find(list, words, num);
		else if (cmd == 0)		//�Է��� END�� ��� ���� �Ҵ� ���� �� ���α׷� ����
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

//��ɾ �޴� �Լ�
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

		if (Mystrcmp(input, insert) == 0)		//�Է��� INSERT�� ��� �ܾ �����ϰ� 1��ȯ
		{
			cin >> name;
			strcpy(words, name);
			return 1;
		}
		else if (Mystrcmp(input, find) == 0)		//�Է��� FIND�� ��� �ܾ �����ϰ� 2��ȯ
		{
			cin >> name;
			strcpy(words, name);
			return 2;
		}
		else if (Mystrcmp(input, end) == 0)		//�Է��� END�� ��� 0 ��ȯ
		{
			return 0;
		}

	}
}

//���� ���� �Լ�
void Insert(char** list, char* words, int& end)
{
	if (end == 0)		//���� �ܾ �ƹ��͵� ����Ǿ����� �ʾ��� ���
	{
		strcpy(*(list + end), words);

		end++;
		PrintVoca(list, end);
		return;
	}
	for (int i = 0; i < end; i++)		//�ܾ 1���� ����Ǿ����� ���
	{
		int state = Mystrcmp(words, *(list + i));
		if (state == 0)			//�ߺ� ���� �˻�
		{
			PrintVoca(list, end);
			delete[] list[end];
			return;
		}
		else if (state == 1)		//�ߺ��� �ƴϰ� �Է¹��� ���ڰ� ���� ���� �տ� ��ġ���־�� �ϴ� ���
		{
			char copy[1024];
			char temp[1024];

			strcpy(copy, words);
			for (int j = i; j <= end; j++)		//�� ĭ�� �迭�� �̷�
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

//�ܾ� Ž�� �Լ�
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

//�ܾ� ��� �Լ�
void PrintVoca(char** list, int end)
{
	for (int i = 0; i < end; i++)
	{
		cout << i << '.' << *(list + i) << endl;
	}
	return;
}

//�ܾ ��ҹ��� ���� ���� ���ϴ� �Լ�
int Mystrcmp(char* a, char* b)
{
	for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++)			//�� ���ڿ��� �� ���� ª�� ���ڿ��� ���̸�ŭ ��
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
	if (strlen(a) < strlen(b))			//���ڿ��� ���� ��
		return 1;
	else if (strlen(a) > strlen(b))
		return 2;
	else
		return 0;
}