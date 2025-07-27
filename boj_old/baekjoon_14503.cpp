#include <iostream>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	int r, c, d; cin >> r >> c >> d;
	int grid[50][50];
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	int cnt{ 0 };
	while (true)
	{
		if(grid[r][c] == 0) cnt++;
		grid[r][c] = -1;

		bool check{ true };
		bool goBack{ false };
		int _r, _c, _d;
		for (int i{ 1 }; i <= 4; i++)
		{
			int dir{ (d - i + 4) % 4 };
			if (dir == 0)
			{
				if (grid[r - 1][c] == 0)
				{
					d = dir;
					check = false;
					r--; break;
				}
				else if (grid[r - 1][c] == -1 && i == 2)
				{
					goBack = true;
					_r = r - 1, _c = c;
				}
			}
			else if (dir == 1)
			{
				if (grid[r][c + 1] == 0)
				{
					d = dir;
					check = false;
					c++; break;
				}
				else if (grid[r][c + 1] == -1 && i == 2)
				{
					goBack = true;
					_r = r, _c = c + 1;
				}
			}
			else if (dir == 2)
			{
				if (grid[r + 1][c] == 0)
				{
					d = dir;
					check = false;
					r++; break;
				}
				else if (grid[r + 1][c] == -1 && i == 2)
				{
					goBack = true;
					_r = r + 1, _c = c;
				}
			}
			else if (dir == 3)
			{
				if (grid[r][c - 1] == 0)
				{
					d = dir;
					check = false;
					c--; break;
				}
				else if (grid[r][c - 1] == -1 && i == 2)
				{
					goBack = true;
					_r = r, _c = c - 1;
				}
			}
		}

		if (check)
		{
			if (goBack)
			{
				r = _r, c = _c;
			}
			else break;
		}
	}
	cout << cnt;
}