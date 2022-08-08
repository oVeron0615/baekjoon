#include <iostream>
using namespace std;

int N, M, cheese{ 0 };
int grid[100][100];
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

void dfs(int, int);
void melt();
void f();

int main()
{
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1) cheese++;
		}
	}

	int ans{ 0 };
	while (cheese != 0)
	{
		dfs(0, 0);
		melt();
		f();
		ans++;
	}
	cout << ans;
}

void dfs(int x, int y)
{
	grid[x][y] = -1;
	for (int i{ 0 }; i < 4; i++)
	{
		int p{ x + dir[0][i] }, q{ y + dir[1][i] };
		if (p >= 0 && p < N && q >= 0 && q < M)
		{
			if (grid[p][q] == 0) dfs(p, q);
		}
	}
}

void melt()
{
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < M; j++)
		{
			if (grid[i][j] == 1)
			{
				int cnt{ 0 };
				for (int k{ 0 }; k < 4; k++)
				{
					int p{ i + dir[0][k] }, q{ j + dir[1][k] };
					if (p >= 0 && p < N && q >= 0 && q < M)
					{
						if (grid[p][q] == -1) cnt++;
					}
				}
				if (cnt >= 2)
				{
					grid[i][j] = 0;
					cheese--;
				}
			}
		}
	}
}

void f()
{
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < M; j++)
		{
			if (grid[i][j] == -1) grid[i][j] = 0;
		}
	}
}