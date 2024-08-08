#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Mystring
{
public:
	char* str = NULL;

	Mystring() {  }
	Mystring(const char* input)		//���ڿ� ���ڸ� ���� ��� �迭 �Ҵ� �� ����
	{
		this->str = new char[strlen(input) + 1];
		strcpy(this->str, input);
	}
	Mystring& operator=(const Mystring& input)		//�Է¹��� Ŭ������ ������ ������ ����
	{
		str = new char[strlen(input.str) + 1];
		strcpy(this->str, input.str);

		return *this;
	}

	Mystring& operator+(const char* string)		//+������ �� ���� Ŭ������ string ���ڿ��� ����
	{
		int len = strlen(this->str) + strlen(string) + 1;
		char* output = new char[len];

		strcpy(output, this->str);
		strcat(output, string);

		delete[] this->str;
		this->str = new char[len];
		strcpy(this->str, output);

		delete[] output;

		return *this;
	}

	friend ostream& operator<<(ostream& os, const Mystring& string);		//Ŭ���� ��� ������

	~Mystring()		//�Ҹ� �� ���ڿ� �Ҵ� ����
	{
		if (str != NULL)
			delete[] str;
	}
};

int main(void)
{
	Mystring my_str;
	Mystring my_str2("���Ǵ� ");
	my_str = my_str2 + "camjun0506@naver.com���� �ּ���";
	cout << my_str;


	return 0;
}

//Ŭ���� ��� ������
ostream& operator<<(ostream& os, const Mystring& string)
{
	os << string.str << '\n';
	return os;
}