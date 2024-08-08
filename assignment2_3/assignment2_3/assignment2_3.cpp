#include <iostream>
using namespace std;

struct Infor		//정보가 저장된 구조체
{
	char name[12] = "이준휘";
	char school[100] = "광운대학교";
	char major[100] = "컴퓨터정보공학부";
	long long int ID = 2018202046;

};

void Rightprint(void);		//입력이 올바른 경우 출력 함수

void Wrongprint(void);		//잘못된 입력일 경우 출력 함수

int main(void)
{
	void (*fp)() = NULL;		//함수 포인터 저장 함수
	int PW = 1234;

	int input;

	cout << "Please input password : ";
	cin >> input;
	if (PW == input)		//비밀번호와 입력이 동일한 경우 
	{
		fp = Rightprint;
		fp();
	}
	else					//비밀번호와 입력이 다른 경우
	{
		fp = Wrongprint;
		fp();
	}

	return 0;
}

//입력이 올바른 경우 함수
void Rightprint(void)
{
	Infor infor;
	cout << "이름 : " << infor.name << endl;
	cout << "학교 : " << infor.school << endl;
	cout << "학과 : " << infor.major << endl;
	cout << "학번 : " << infor.ID << endl;

	return;
}

//입력이 틀린 경우 함수
void Wrongprint(void)
{
	cout << "Wrong Password" << endl;

	return;
}