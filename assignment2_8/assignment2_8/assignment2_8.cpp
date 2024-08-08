#include <iostream>
using namespace std;

class Animal
{
private:
	int Foodchain;
	int Distance;
	int Arrival;

public:
	Animal(int Foodchain) {
		Arrival = false; Distance = 0;
		this->Foodchain = Foodchain;
	}
	virtual void run() = 0;

	//�Ÿ� ����� �Լ�
	int GetDistance()
	{
		return this->Distance;
	}
	void PushDistance(int input)
	{
		this->Distance = input;
		return;
	}

	//�������� ����� �Լ�
	int GetArrival()
	{
		return this->Arrival;
	}
	void PushArrival(int input)
	{
		this->Arrival = input;
		return;
	}
};

//������ ���� class
class Frog :public Animal
{
public:
	int seq;
	Frog() : Animal(4) { seq = -1; }
	virtual void run()		//2 �̵�
	{
		PushDistance(this->GetDistance() + 2);
		return;
	}
};

//�� ���� class
class Snake :public Animal
{
public:
	int seq;
	Snake() : Animal(3) { seq = -1; }
	virtual void run()		//1 �̵�
	{
		PushDistance(this->GetDistance() + 1);;
		return;
	}
};

//������ ���� class
class Eagle :public Animal
{
public:
	int seq;
	Eagle() : Animal(2) { seq = -1; }
	virtual void run()		//4 �̵�
	{
		PushDistance(this->GetDistance() + 4);;
		return;
	}

};
class Tiger :public Animal
{
public:
	int seq;
	Tiger() : Animal(1) { seq = -1; }
	virtual void run()		//3 �̵�
	{
		PushDistance(this->GetDistance() + 3);
		return;
	}

};

int main(void)
{
	Frog frog;
	Snake snake;
	Eagle eagle;
	Tiger tiger;

	//���ڿ��� ������� �Է¹ް� �� ������ �� ���� Ŭ������ ����
	char input[4];
	cout << "Select Animal Sequence(E,S,E,T / ex : S F T E) :";
	cin >> input[0] >> input[1] >> input[2] >> input[3];
	for (int i = 0; i < 4; i++)
	{
		if (input[i] == 'F')
		{
			frog.seq = i;
		}
		else if (input[i] == 'S')
		{
			snake.seq = i;
		}
		else if (input[i] == 'E')
		{
			eagle.seq = i;
		}
		else if (input[i] == 'T')
		{
			tiger.seq = i;
		}
	}

	for (int i = 0;; i++)
	{
		char arr[11] = "0000000000";

		//�� ������ �����߰ų� ������ �ƴҰ�� �������� ����, �ݴ��� ��쿡�� �����̰� �迭�� ��ġ ǥ��
		if (frog.seq <= i && (frog.GetArrival() == false))
		{
			frog.run();
			if (frog.GetDistance() > 10)
			{
				frog.PushArrival(true);
			}
			else
			{
				arr[frog.GetDistance() - 1] = 'F';
			}
		}
		if (snake.seq <= i && (snake.GetArrival() == false))
		{
			snake.run();
			if (snake.GetDistance() > 10)
			{
				snake.PushArrival(true);
			}
			else
			{
				arr[snake.GetDistance() - 1] = 'S';
			}
		}
		if (eagle.seq <= i && (eagle.GetArrival() == false))
		{
			eagle.run();
			if (eagle.GetDistance() > 10)
			{
				eagle.PushArrival(true);
			}
			else
			{
				arr[eagle.GetDistance() - 1] = 'E';
			}
		}
		if (tiger.seq <= i && (tiger.GetArrival() == false))
		{
			tiger.run();
			if (tiger.GetDistance() > 10)
			{
				tiger.PushArrival(true);
			}
			else
			{
				arr[tiger.GetDistance() - 1] = 'T';
			}
		}

		//�� ������ ��ġ�� ���� ��� ���̻罽�� ���� �ʱ� ��ġ�� �̵�
		if ((frog.GetDistance() == snake.GetDistance()) || (frog.GetDistance() == eagle.GetDistance()) || (frog.GetDistance() == tiger.GetDistance()))
		{
			frog.PushDistance(0);
		}
		if ((snake.GetDistance() == eagle.GetDistance()) || (snake.GetDistance() == tiger.GetDistance()))
		{
			snake.PushDistance(0);
		}
		if ((eagle.GetDistance() == tiger.GetDistance()))
		{
			eagle.PushDistance(0);
		}

		//�迭 ���
		for (int i = 0; i < 10; i++)
			cout << arr[i] << '\t';
		cout << endl;

		//��� ������ �������� ��� �Լ� ����
		if ((frog.GetArrival() == true) && (snake.GetArrival() == true) && (eagle.GetArrival() == true) && (tiger.GetArrival() == true))
		{
			return 0;
		}
	}





}