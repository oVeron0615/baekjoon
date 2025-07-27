#include <iostream>
#include <array>
#include <climits>
using namespace std;

array<array<bool, 8>, 8> grid;

int reverseGrid(int N, int count, int min, int loc);

int main()
{
	int N;

	//������ �Է�
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	//������
	cout << reverseGrid(N, 0, INT_MAX, 0);
}

int reverseGrid(int N, int count, int min, int loc)
{
	//�� ���������� �浹�� �鵹 �� ���� �� ���� ���� �� ���� ���Ѵ�.
	if (loc == N * 2)
	{
		int cnt1{ 0 };
		for (int i{ 0 }; i < N; i++)
		{
			for (int j{ 0 }; j < N; j++)
			{
				if (grid[i][j]) cnt1++;
			}
		}
		int plus = cnt1 < N * N - cnt1 ? cnt1 : N * N - cnt1;
		count += plus;

		if (min > count)
		{
			min = count;
			return min;
		}
		else return min;
	}

	//�� ���� ������ ����� �����Ƿ� ���̳� ���� ������ ����� ���� �ִ� 2�� 16��
	//bruteforce�� ��͸� �̿��� ���� ������ ����
	if (loc < N)
	{
		min = reverseGrid(N, count, min, loc + 1);
		for (int j{ 0 }; j < N; j++)
		{
			if (grid[loc][j]) grid[loc][j] = false;
			else grid[loc][j] = true;
		}
		min = reverseGrid(N, count + 1, min, loc + 1);
		for (int j{ 0 }; j < N; j++)
		{
			if (grid[loc][j]) grid[loc][j] = false;
			else grid[loc][j] = true;
		}
	}
	else
	{
		min = reverseGrid(N, count, min, loc + 1);
		for (int i{ 0 }; i < N; i++)
		{
			if (grid[i][loc - N]) grid[i][loc - N] = false;
			else grid[i][loc - N] = true;
		}
		min = reverseGrid(N, count + 1, min, loc + 1);
		for (int i{ 0 }; i < N; i++)
		{
			if (grid[i][loc - N]) grid[i][loc - N] = false;
			else grid[i][loc - N] = true;
		}
	}

	return min;
}