
#include <iostream>
using namespace std;

class Mystring
{
private:
	char MyStr[1024];
public:
	char* MyStrcpy(char* src, int len)		//문자열 복사 함수
	{
		for (int i = 0; i < len; i++)
		{
			this->MyStr[i] = src[i];
		}
		this->MyStr[len] = '\0';

		return this->MyStr;
	}
	int Find_char(char c)		//문자 탐색 함수
	{
		for (int i = 0; this->MyStr[i] != '\0'; i++)
		{
			if (this->MyStr[i] == c)
			{
				return i;
			}
		}
		return -1;
	}
};

int main(void)
{
	char inputStr[1024];
	char inputChar;
	Mystring str;

	cin >> inputStr;			//문자열 입력받음

	int length = 0;
	for (int i = 0; inputStr[i] != '\0'; i++)		//길이 측정
	{
		length++;
	}
	;

	cout << "Copy String : " << str.MyStrcpy(inputStr, length) << endl;		//문자열 복사
	cin >> inputChar;
	cout << str.Find_char(inputChar);		//문자 탐색



	return 0;
}