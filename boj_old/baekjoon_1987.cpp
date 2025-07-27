#include <iostream>
using namespace std;

int R, C, mx{ 0 }, cnt{ 0 };
char grid[20][20];
bool alpha[26];
int dir[2][4] = { {-1, 1, 0, 0},{0, 0, -1, 1} };

void dfs(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C;
	for (int i{ 0 }; i < R; i++)
	{
		for (int j{ 0 }; j < C; j++)
		{
			cin >> grid[i][j];
		}
	}

	dfs(0, 0);
	cout << mx;
}

void dfs(int x, int y)
{
	if (!alpha[grid[x][y] - 'A'])
	{
		alpha[grid[x][y] - 'A'] = true; cnt++;
		for (int i{ 0 }; i < 4; i++)
		{
			int p{ x + dir[0][i] }, q{ y + dir[1][i] };
			if (p >= 0 && p < R && q >= 0 && q < C)
			{
				dfs(p, q);
			}
		}
		alpha[grid[x][y] - 'A'] = false; cnt--;
	}
	else mx = max(mx, cnt);
}