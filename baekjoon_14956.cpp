#include <iostream>
#include <vector>
using namespace std;

/*
direction: ㄷ자가 가리키는 방향 
1 - 위, 2 - 아래, 3 - 왼쪽, 4 - 오른쪽
*/
void self(int n, int m, int direction);

/*
apartment 벡터에 좌표를 추론할 수 있는 값 저장
1 - 왼쪽 아래, 2 - 오른쪽 아래, 3 - 왼쪽 위, 4 - 오른쪽 위
*/
vector<int> apartment;

int main()
{
	int n, m, x{ 1 }, y{ 1 };

	cin >> n >> m;
	self(n, m, 1); //초기 방향은 1

	//좌표 추정
	for (int i{ 0 }; i < apartment.size(); i++)
	{
		switch (apartment[i])
		{
		case 1: break;
		case 2: x += n / 2; break;
		case 3: y += n / 2; break;
		case 4: x += n / 2; y += n / 2; break;
		}
		n /= 2;
	}

	cout << x << " " << y;
}

void self(int n, int m, int direction)
{
	if (n == 0) return;
	n /= 2;

	//방향에 따라 각 사분면에서 ㄷ자가 가리키는 방향이 다름 
	switch (direction)
	{
	case 1:
		if (n * n * 1 >= m)
		{
			apartment.push_back(1);
			self(n, m, 4);
		}
		else if (n * n * 2 >= m)
		{
			apartment.push_back(3);
			self(n, m - n * n * 1, 1);
		}
		else if (n * n * 3 >= m)
		{
			apartment.push_back(4);
			self(n, m - n * n * 2, 1);
		}
		else
		{
			apartment.push_back(2);
			self(n, m - n * n * 3, 3);
		}
		break;
	case 2:
		if (n * n * 1 >= m)
		{
			apartment.push_back(4);
			self(n, m, 3);
		}
		else if (n * n * 2 >= m)
		{
			apartment.push_back(2);
			self(n, m - n * n * 1, 2);
		}
		else if (n * n * 3 >= m)
		{
			apartment.push_back(1);
			self(n, m - n * n * 2, 2);
		}
		else
		{
			apartment.push_back(3);
			self(n, m - n * n * 3, 4);
		}
		break;
	case 3:
		if (n * n * 1 >= m)
		{
			apartment.push_back(4);
			self(n, m, 2);
		}
		else if (n * n * 2 >= m)
		{
			apartment.push_back(3);
			self(n, m - n * n * 1, 3);
		}
		else if (n * n * 3 >= m)
		{
			apartment.push_back(1);
			self(n, m - n * n * 2, 3);
		}
		else
		{
			apartment.push_back(2);
			self(n, m - n * n * 3, 1);
		}
		break;
	case 4:
		if (n * n * 1 >= m)
		{
			apartment.push_back(1);
			self(n, m, 1);
		}
		else if (n * n * 2 >= m)
		{
			apartment.push_back(2);
			self(n, m - n * n * 1, 4);
		}
		else if (n * n * 3 >= m)
		{
			apartment.push_back(4);
			self(n, m - n * n * 2, 4);
		}
		else
		{
			apartment.push_back(3);
			self(n, m - n * n * 3, 2);
		}
		break;
	}
}