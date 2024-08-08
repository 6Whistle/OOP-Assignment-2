#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Mystring
{
public:
	char* str = NULL;

	Mystring() {  }
	Mystring(const char* input)		//문자열 인자를 받을 경우 배열 할당 및 저장
	{
		this->str = new char[strlen(input) + 1];
		strcpy(this->str, input);
	}
	Mystring& operator=(const Mystring& input)		//입력받은 클래스와 동일한 값으로 만듬
	{
		str = new char[strlen(input.str) + 1];
		strcpy(this->str, input.str);

		return *this;
	}

	Mystring& operator+(const char* string)		//+연산자 시 기존 클래스에 string 문자열을 더함
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

	friend ostream& operator<<(ostream& os, const Mystring& string);		//클래스 출력 연산자

	~Mystring()		//소멸 시 문자열 할당 해제
	{
		if (str != NULL)
			delete[] str;
	}
};

int main(void)
{
	Mystring my_str;
	Mystring my_str2("문의는 ");
	my_str = my_str2 + "camjun0506@naver.com으로 주세요";
	cout << my_str;


	return 0;
}

//클래스 출력 연산자
ostream& operator<<(ostream& os, const Mystring& string)
{
	os << string.str << '\n';
	return os;
}