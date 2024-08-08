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

	//거리 입출력 함수
	int GetDistance()
	{
		return this->Distance;
	}
	void PushDistance(int input)
	{
		this->Distance = input;
		return;
	}

	//도착여부 입출력 함수
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

//개구리 정보 class
class Frog :public Animal
{
public:
	int seq;
	Frog() : Animal(4) { seq = -1; }
	virtual void run()		//2 이동
	{
		PushDistance(this->GetDistance() + 2);
		return;
	}
};

//뱀 정보 class
class Snake :public Animal
{
public:
	int seq;
	Snake() : Animal(3) { seq = -1; }
	virtual void run()		//1 이동
	{
		PushDistance(this->GetDistance() + 1);;
		return;
	}
};

//독수리 정보 class
class Eagle :public Animal
{
public:
	int seq;
	Eagle() : Animal(2) { seq = -1; }
	virtual void run()		//4 이동
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
	virtual void run()		//3 이동
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

	//문자열을 순서대로 입력받고 각 순서를 각 동물 클래스에 저장
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

		//각 동물이 도착했거나 순서가 아닐경우 움직이지 않음, 반대의 경우에는 움직이고 배열에 위치 표시
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

		//각 동물의 위치가 같을 경우 먹이사슬에 따라 초기 위치로 이동
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

		//배열 출력
		for (int i = 0; i < 10; i++)
			cout << arr[i] << '\t';
		cout << endl;

		//모든 동물이 도착했을 경우 함수 종료
		if ((frog.GetArrival() == true) && (snake.GetArrival() == true) && (eagle.GetArrival() == true) && (tiger.GetArrival() == true))
		{
			return 0;
		}
	}





}