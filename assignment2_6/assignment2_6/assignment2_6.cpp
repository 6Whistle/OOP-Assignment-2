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
	void NewAccount(void)		//계좌 생성 함수
	{
		this->name = new char[12];
		this->Account_Number = new char[100];

		cin >> this->name >> this->Account_Number;
		cout << "계좌생성" << endl;

		return;
	}
	void DepositAccount(char* inputAc, int inputMo)		//입금 함수
	{
		if (strcmp(inputAc, this->Account_Number) == 0)
		{
			this->money += inputMo;
		}
		return;
	}
	void WithdrawAccount(char* inputAc, int inputMo)		//출금 함수
	{
		if (strcmp(inputAc, this->Account_Number) == 0)
		{
			this->money -= inputMo;
		}

		return;
	}
	void PrintAccount(void)		//금액 출력 함수
	{
		cout << "이름 : " << this->name << "\tACount_Number : " << this->Account_Number << "\tMoney : " << this->money << endl;
		return;
	}
	void DestructAccount(void)		//계좌 삭제 함수
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
		cout << "메모리 할당 실패" << endl;
		return -1;
	}

	while (true)
	{
		char cmd[12];
		char inputAc[100];
		int inputMo;

		cin >> cmd;
		if (strcmp(cmd, "NEW") == 0)		//계좌 생성을 입력받은 경우 5개 미만일 경우 계좌 생성
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
		else if (strcmp(cmd, "DEPOSIT") == 0)		//입금을 입력받은 경우 계좌가 있을 때 계좌 생성
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
		else if (strcmp(cmd, "WITHDRAW") == 0)		//출금을 입력받은 경우 계좌가 있을 때 계좌 생성
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
		else if (strcmp(cmd, "PRINT") == 0)		//계좌 출력을 입력받은 경우 계좌 출력 함수 호출
		{
			for (int i = 0; i < count; i++)
			{
				cout << i << '\t';
				account[i].PrintAccount();
			}
		}
		else if (strcmp(cmd, "EXIT") == 0)		//종료를 입력받은 경우 계좌 메모리 할당 해제 후 함수 종료
		{

			for (int i = 0; i < count; i++)
			{
				account[i].DestructAccount();
				cout << "계좌삭제 :" << i << endl;
			}
			delete[] account;
			return 0;
		}
	}
}