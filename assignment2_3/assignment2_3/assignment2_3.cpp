#include <iostream>
using namespace std;

struct Infor		//������ ����� ����ü
{
	char name[12] = "������";
	char school[100] = "������б�";
	char major[100] = "��ǻ���������к�";
	long long int ID = 2018202046;

};

void Rightprint(void);		//�Է��� �ùٸ� ��� ��� �Լ�

void Wrongprint(void);		//�߸��� �Է��� ��� ��� �Լ�

int main(void)
{
	void (*fp)() = NULL;		//�Լ� ������ ���� �Լ�
	int PW = 1234;

	int input;

	cout << "Please input password : ";
	cin >> input;
	if (PW == input)		//��й�ȣ�� �Է��� ������ ��� 
	{
		fp = Rightprint;
		fp();
	}
	else					//��й�ȣ�� �Է��� �ٸ� ���
	{
		fp = Wrongprint;
		fp();
	}

	return 0;
}

//�Է��� �ùٸ� ��� �Լ�
void Rightprint(void)
{
	Infor infor;
	cout << "�̸� : " << infor.name << endl;
	cout << "�б� : " << infor.school << endl;
	cout << "�а� : " << infor.major << endl;
	cout << "�й� : " << infor.ID << endl;

	return;
}

//�Է��� Ʋ�� ��� �Լ�
void Wrongprint(void)
{
	cout << "Wrong Password" << endl;

	return;
}