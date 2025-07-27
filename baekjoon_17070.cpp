#include <iostream>
#include <vector>
using namespace std;

int N, cnt{ 0 };
bool house[17][17];

void bfs(int, int, int);

int main()
{
	cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		for (int j{ 1 }; j <= N; j++)
		{
			cin >> house[i][j];
		}
	}

	bfs(1, 2, 0);
	cout << cnt;
}

void bfs(int x, int y, int z)
{
	if (x == N && y == N)
	{
		cnt++;
		return;
	}

	int a{ x + 1 }, b{ y + 1 };

	if (z == 0)
	{
		if (b <= N && !house[x][b]) bfs(x, b, 0);
		if (a <= N && b <= N && !house[a][b] && !house[x][b] && !house[a][y]) bfs(a, b, 1);
	}
	else if (z == 1)
	{
		if (b <= N && !house[x][b]) bfs(x, b, 0);
		if (a <= N && b <= N && !house[a][b] && !house[x][b] && !house[a][y]) bfs(a, b, 1);
		if (a <= N && !house[a][y]) bfs(a, y, 2);
	}
	else if (z == 2)
	{
		if (a <= N && b <= N && !house[a][b] && !house[x][b] && !house[a][y]) bfs(a, b, 1);
		if (a <= N && !house[a][y]) bfs(a, y, 2);
	}
}