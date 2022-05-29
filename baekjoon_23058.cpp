#include <iostream>
#include <array>
#include <climits>
using namespace std;

array<array<bool, 8>, 8> grid;

int reverseGrid(int N, int count, int min, int loc);

int main()
{
	int N;

	//격자판 입력
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	//뒤집기
	cout << reverseGrid(N, 0, INT_MAX, 0);
}

int reverseGrid(int N, int count, int min, int loc)
{
	//다 뒤집었으면 흑돌과 백돌 중 수가 더 적은 쪽의 돌 수를 더한다.
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

	//뭘 먼저 뒤집든 상관은 없으므로 행이나 열을 뒤집을 경우의 수는 최대 2의 16승
	//bruteforce와 재귀를 이용해 전부 뒤집어 본다
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