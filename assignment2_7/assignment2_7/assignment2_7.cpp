#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class ����
{
private:
	char U_name[20];
	int year;
	char U_StuID[20];
public:
	//U_name ����� �Լ�
	char* Get_U_name(void)
	{
		return this->U_name;
	}
	void Input_U_name(char* input)
	{
		strcpy(this->U_name, input);
		return;
	}

	//year ����� �Լ�
	int Get_year(void)
	{
		return this->year;
	}
	void Input_year(int input)
	{
		this->year = input;
		return;
	}

	//U_StuID ����� �Լ�
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

class ��ǻ���������� :public ����
{
private:
	char Object_Oriented_Programing;
	char Digtal_Logic_Circuit;
public:
	//OOP ����� �Լ�
	char Get_OOP(void)
	{
		return this->Object_Oriented_Programing;
	}
	void Input_OOP(char input)
	{
		this->Object_Oriented_Programing = input;
		return;
	}

	//DLC ����� �Լ�
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

class �л����� :public ��ǻ����������
{
private:
	char Name[10];
	int age;
public:
	//Name ����� �Լ�
	char* Get_Name(void)
	{
		return this->Name;
	}
	void Input_Name(char* input)
	{
		strcpy(this->Name, input);
		return;
	}

	//age ����� �Լ�
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

void NewInfo(�л�����&);		//�л����� �߰� �Լ�
void FindInfo(�л�����&, char*, char*);		//�л����� Ž�� �Լ�


int main(void)
{
	int count = 0;
	�л�����** studentinfo;
	studentinfo = new �л�����*;
	*studentinfo = new �л�����[100];

	while (true)
	{
		char cmd[10];
		cin >> cmd;
		if (strcmp(cmd, "INSERT") == 0)		//�Է��� ��ɹ��� ��� �Է¹��� ������ 100�� �̸��� �� ���� ����
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
		else if (strcmp(cmd, "FIND") == 0)		//�̸��� ID�� ���� �л����� Ž�� �Լ� ȣ��
		{
			char inputname[10];
			char inputID[20];

			cin >> inputname >> inputID;
			for (int i = 0; i < count; i++)
			{
				FindInfo(*((*studentinfo) + i), inputname, inputID);
			}
		}
		else if (strcmp(cmd, "EXIT") == 0)		//���� �Է� �� �迭 �Ҵ� ���� �� �Լ� ����
		{
			delete[] * studentinfo;
			delete studentinfo;
			return 0;
		}

	}
}

//�л� ������ �Է¹޴� �Լ�
void NewInfo(�л�����& studentInfo)
{
	char inputstr[20];
	char inputname[10];
	char inputchar;
	int inputint;

	cout << "�б� : ";
	cin >> inputstr;
	studentInfo.Input_U_name(inputstr);

	cout << "�й� : ";
	cin >> inputstr;
	studentInfo.Input_U_StuID(inputstr);

	cout << "�г� : ";
	cin >> inputint;
	studentInfo.Input_year(inputint);

	cout << "��ü�������α׷��� ���� : ";
	cin >> inputchar;
	studentInfo.Input_OOP(inputchar);

	cout << "�����г�ȸ�� ���� : ";
	cin >> inputchar;
	studentInfo.Input_DLC(inputchar);

	cout << "�̸� : ";
	cin >> inputname;
	studentInfo.Input_Name(inputname);

	cout << "���� : ";
	cin >> inputint;
	studentInfo.Input_age(inputint);

	return;
}

//�̸��� ID�� ���� ��� ���� ����ϴ� �Լ�
void FindInfo(�л�����& studentInfo, char* findname, char* findID)
{

	if (strcmp(findname, studentInfo.Get_Name()) == 0)
	{
		if (strcmp(findID, studentInfo.Get_U_StuID()) == 0)
		{
			cout << "\n\n�б� : " << studentInfo.Get_U_name() << endl;
			cout << "�й� : " << studentInfo.Get_U_StuID() << endl;
			cout << "�г� : " << studentInfo.Get_year() << endl;
			cout << "��ü�������α׷��� ���� : " << studentInfo.Get_OOP() << endl;
			cout << "�����г�ȸ�� ���� : " << studentInfo.Get_DLC() << endl;
		}
	}
	return;
}