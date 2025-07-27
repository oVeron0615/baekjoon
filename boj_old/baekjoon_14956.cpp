#include <iostream>
#include <vector>
using namespace std;

/*
direction: ���ڰ� ����Ű�� ���� 
1 - ��, 2 - �Ʒ�, 3 - ����, 4 - ������
*/
void self(int n, int m, int direction);

/*
apartment ���Ϳ� ��ǥ�� �߷��� �� �ִ� �� ����
1 - ���� �Ʒ�, 2 - ������ �Ʒ�, 3 - ���� ��, 4 - ������ ��
*/
vector<int> apartment;

int main()
{
	int n, m, x{ 1 }, y{ 1 };

	cin >> n >> m;
	self(n, m, 1); //�ʱ� ������ 1

	//��ǥ ����
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

	//���⿡ ���� �� ��и鿡�� ���ڰ� ����Ű�� ������ �ٸ� 
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