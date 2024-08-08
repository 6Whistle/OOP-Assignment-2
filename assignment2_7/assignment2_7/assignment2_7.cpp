#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class 대학
{
private:
	char U_name[20];
	int year;
	char U_StuID[20];
public:
	//U_name 입출력 함수
	char* Get_U_name(void)
	{
		return this->U_name;
	}
	void Input_U_name(char* input)
	{
		strcpy(this->U_name, input);
		return;
	}

	//year 입출력 함수
	int Get_year(void)
	{
		return this->year;
	}
	void Input_year(int input)
	{
		this->year = input;
		return;
	}

	//U_StuID 입출력 함수
	char* Get_U_StuID(void)
	{
		return this->U_StuID;
	}
	void Input_U_StuID(char* input)
	{
		strcpy(this->U_StuID, input);
		return;
	}
};

class 컴퓨터정보공학 :public 대학
{
private:
	char Object_Oriented_Programing;
	char Digtal_Logic_Circuit;
public:
	//OOP 입출력 함수
	char Get_OOP(void)
	{
		return this->Object_Oriented_Programing;
	}
	void Input_OOP(char input)
	{
		this->Object_Oriented_Programing = input;
		return;
	}

	//DLC 입출력 함수
	char Get_DLC(void)
	{
		return this->Digtal_Logic_Circuit;
	}
	void Input_DLC(char input)
	{
		this->Digtal_Logic_Circuit = input;
		return;
	}
};

class 학생정보 :public 컴퓨터정보공학
{
private:
	char Name[10];
	int age;
public:
	//Name 입출력 함수
	char* Get_Name(void)
	{
		return this->Name;
	}
	void Input_Name(char* input)
	{
		strcpy(this->Name, input);
		return;
	}

	//age 입출력 함수
	int Get_age(void)
	{
		return this->age;
	}
	void Input_age(int input)
	{
		this->age = input;
		return;
	}
};

void NewInfo(학생정보&);		//학생정보 추가 함수
void FindInfo(학생정보&, char*, char*);		//학생정보 탐색 함수


int main(void)
{
	int count = 0;
	학생정보** studentinfo;
	studentinfo = new 학생정보*;
	*studentinfo = new 학생정보[100];

	while (true)
	{
		char cmd[10];
		cin >> cmd;
		if (strcmp(cmd, "INSERT") == 0)		//입력을 명령받은 경우 입력받은 정보가 100개 미만일 시 정보 저장
		{
			if (count < 100)
			{
				NewInfo(*((*studentinfo) + count));
				count++;
			}
			else
			{
				cout << "Limit Number is 100" << endl;
			}
		}
		else if (strcmp(cmd, "FIND") == 0)		//이름과 ID를 통해 학생정보 탐색 함수 호출
		{
			char inputname[10];
			char inputID[20];

			cin >> inputname >> inputID;
			for (int i = 0; i < count; i++)
			{
				FindInfo(*((*studentinfo) + i), inputname, inputID);
			}
		}
		else if (strcmp(cmd, "EXIT") == 0)		//종료 입력 시 배열 할당 해제 후 함수 종료
		{
			delete[] * studentinfo;
			delete studentinfo;
			return 0;
		}

	}
}

//학생 정보를 입력받는 함수
void NewInfo(학생정보& studentInfo)
{
	char inputstr[20];
	char inputname[10];
	char inputchar;
	int inputint;

	cout << "학교 : ";
	cin >> inputstr;
	studentInfo.Input_U_name(inputstr);

	cout << "학번 : ";
	cin >> inputstr;
	studentInfo.Input_U_StuID(inputstr);

	cout << "학년 : ";
	cin >> inputint;
	studentInfo.Input_year(inputint);

	cout << "객체지향프로그래밍 학점 : ";
	cin >> inputchar;
	studentInfo.Input_OOP(inputchar);

	cout << "디지털논리회로 학점 : ";
	cin >> inputchar;
	studentInfo.Input_DLC(inputchar);

	cout << "이름 : ";
	cin >> inputname;
	studentInfo.Input_Name(inputname);

	cout << "나이 : ";
	cin >> inputint;
	studentInfo.Input_age(inputint);

	return;
}

//이름과 ID가 같을 경우 정보 출력하는 함수
void FindInfo(학생정보& studentInfo, char* findname, char* findID)
{

	if (strcmp(findname, studentInfo.Get_Name()) == 0)
	{
		if (strcmp(findID, studentInfo.Get_U_StuID()) == 0)
		{
			cout << "\n\n학교 : " << studentInfo.Get_U_name() << endl;
			cout << "학번 : " << studentInfo.Get_U_StuID() << endl;
			cout << "학년 : " << studentInfo.Get_year() << endl;
			cout << "객체지향프로그래밍 학점 : " << studentInfo.Get_OOP() << endl;
			cout << "디지털논리회로 학점 : " << studentInfo.Get_DLC() << endl;
		}
	}
	return;
}