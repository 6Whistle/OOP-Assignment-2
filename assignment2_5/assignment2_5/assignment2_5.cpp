
#include <iostream>
using namespace std;

class Mystring
{
private:
	char MyStr[1024];
public:
	char* MyStrcpy(char* src, int len)		//���ڿ� ���� �Լ�
	{
		for (int i = 0; i < len; i++)
		{
			this->MyStr[i] = src[i];
		}
		this->MyStr[len] = '\0';

		return this->MyStr;
	}
	int Find_char(char c)		//���� Ž�� �Լ�
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

	cin >> inputStr;			//���ڿ� �Է¹���

	int length = 0;
	for (int i = 0; inputStr[i] != '\0'; i++)		//���� ����
	{
		length++;
	}
	;

	cout << "Copy String : " << str.MyStrcpy(inputStr, length) << endl;		//���ڿ� ����
	cin >> inputChar;
	cout << str.Find_char(inputChar);		//���� Ž��



	return 0;
}