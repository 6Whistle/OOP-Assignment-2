#include <iostream>
#include <cstring>
using namespace std;

class MyAccount
{
private:
	unsigned int money = 0;
	char* name;
	char* Account_Number;

public:
	void NewAccount(void)		//���� ���� �Լ�
	{
		this->name = new char[12];
		this->Account_Number = new char[100];

		cin >> this->name >> this->Account_Number;
		cout << "���»���" << endl;

		return;
	}
	void DepositAccount(char* inputAc, int inputMo)		//�Ա� �Լ�
	{
		if (strcmp(inputAc, this->Account_Number) == 0)
		{
			this->money += inputMo;
		}
		return;
	}
	void WithdrawAccount(char* inputAc, int inputMo)		//��� �Լ�
	{
		if (strcmp(inputAc, this->Account_Number) == 0)
		{
			this->money -= inputMo;
		}

		return;
	}
	void PrintAccount(void)		//�ݾ� ��� �Լ�
	{
		cout << "�̸� : " << this->name << "\tACount_Number : " << this->Account_Number << "\tMoney : " << this->money << endl;
		return;
	}
	void DestructAccount(void)		//���� ���� �Լ�
	{
		delete[] this->name;
		delete[] this->Account_Number;

		return;
	}
};

int main(void)
{
	MyAccount* account = NULL;
	int count = 0;
	account = new class MyAccount[5];
	if (account == NULL)
	{
		cout << "�޸� �Ҵ� ����" << endl;
		return -1;
	}

	while (true)
	{
		char cmd[12];
		char inputAc[100];
		int inputMo;

		cin >> cmd;
		if (strcmp(cmd, "NEW") == 0)		//���� ������ �Է¹��� ��� 5�� �̸��� ��� ���� ����
		{
			if (count < 5)
			{
				account[count].NewAccount();
				count++;
			}
			else
			{
				cout << "Number of Account is Limited" << endl;
			}
		}
		else if (strcmp(cmd, "DEPOSIT") == 0)		//�Ա��� �Է¹��� ��� ���°� ���� �� ���� ����
		{
			if (count == 0)
			{
				cout << "Number of Account is 0" << endl;
			}
			else
			{
				cin >> inputAc >> inputMo;

				for (int i = 0; i < count; i++)
				{
					account[i].DepositAccount(inputAc, inputMo);
				}
			}
		}
		else if (strcmp(cmd, "WITHDRAW") == 0)		//����� �Է¹��� ��� ���°� ���� �� ���� ����
		{
			if (count == 0)
			{
				cout << "Number of Account is 0" << endl;
			}
			else
			{
				cin >> inputAc >> inputMo;

				for (int i = 0; i < count; i++)
				{
					account[i].WithdrawAccount(inputAc, inputMo);
				}
			}
		}
		else if (strcmp(cmd, "PRINT") == 0)		//���� ����� �Է¹��� ��� ���� ��� �Լ� ȣ��
		{
			for (int i = 0; i < count; i++)
			{
				cout << i << '\t';
				account[i].PrintAccount();
			}
		}
		else if (strcmp(cmd, "EXIT") == 0)		//���Ḧ �Է¹��� ��� ���� �޸� �Ҵ� ���� �� �Լ� ����
		{

			for (int i = 0; i < count; i++)
			{
				account[i].DestructAccount();
				cout << "���»��� :" << i << endl;
			}
			delete[] account;
			return 0;
		}
	}
}