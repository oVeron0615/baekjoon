#include <iostream>
#include <array>
#include <climits>
#include <algorithm>
using namespace std;

array<array<bool, 8>, 8> grid;

int ans{ INT_MAX }, N;
void reversegrid(int loc, int count);

int main()
{
	//�Է�
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}
	reversegrid(0, 0);

	cout << ans;
}

void reversegrid(int loc, int count)
{
	if (loc == N * 2)
	{
		int cnt{ 0 };
		for (int i{ 0 }; i < N; i++)
		{
			for (int j{ 0 }; j < N; j++)
			{
				if (grid[i][j]) cnt++;
			}
		}

		ans = min(ans, count + min(cnt, N * N - cnt));
		return;
	}

	//��
	if (loc < N)
	{
		//�� ������
		reversegrid(loc + 1, count);

		//������
		for (int i{ 0 }; i < N; i++) grid[loc][i] = !grid[loc][i];
		reversegrid(loc + 1, count + 1);
		for (int i{ 0 }; i < N; i++) grid[loc][i] = !grid[loc][i];
	}

	//��
	else
	{
		//�� ������
		reversegrid(loc + 1, count);

		//������
		for (int i{ 0 }; i < N; i++) grid[i][loc - N] = !grid[i][loc - N];
		reversegrid(loc + 1, count + 1);
		for (int i{ 0 }; i < N; i++) grid[i][loc - N] = !grid[i][loc - N];
	}
}