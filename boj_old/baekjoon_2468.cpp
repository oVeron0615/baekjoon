#include <iostream>
using namespace std;

int N, mx{}, cnt;
int grid[101][101];
bool safe_and_danger[101][101];
int dir[2][4] = {{0, -1, 0, 1}, {-1, 0, 1, 0} };

void land_search(int, int);

int main()
{
	cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		for (int j{ 1 }; j <= N; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int height{ 0 }; height <= 100; height++)
	{
		for (int i{ 1 }; i <= N; i++)
		{
			for (int j{ 1 }; j <= N; j++)
			{
				if (grid[i][j] <= height) safe_and_danger[i][j] = false;
				else safe_and_danger[i][j] = true;
			}
		}
		
		cnt = 0;
		for (int i{ 1 }; i <= N; i++)
		{
			for (int j{ 1 }; j <= N; j++)
			{
				if (safe_and_danger[i][j])
				{
					cnt++;
					safe_and_danger[i][j] = false;
					for (int k{ 0 }; k < 4; k++)
					{
						int x{ i + dir[0][k] }, y{ j + dir[1][k] };
						if(x > 0 && x <= N && y > 0 && y <= N
							&& safe_and_danger[x][y]) land_search(x, y);
					}
				}
			}
		}
		mx = max(mx, cnt);
	}
	cout << mx;
}

void land_search(int i, int j)
{
	safe_and_danger[i][j] = false;
	for (int k{ 0 }; k < 4; k++)
	{
		int x{ i + dir[0][k] }, y{ j + dir[1][k] };
		if (x > 0 && x <= N && y > 0 && y <= N
			&& safe_and_danger[x][y]) land_search(x, y);
	}
}