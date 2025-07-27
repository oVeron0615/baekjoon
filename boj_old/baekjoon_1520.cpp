#include <iostream>
#include <cstring>
using namespace std;

int map[500][500], dp[500][500];
int M, N;

int f(int, int);

int main()
{
	cin >> M >> N;

	for (int i{ 0 }; i < M; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	int x{ 0 }, y{ 0 };

	cout << f(x, y);
}

int f(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == M - 1 && y == N - 1) return 1;

	int sum{ 0 };
	if (x != 0 && map[x - 1][y] < map[x][y]) sum += f(x - 1, y);
	if (x != M - 1 && map[x + 1][y] < map[x][y]) sum += f(x + 1, y);
	if (y != 0 && map[x][y - 1] < map[x][y]) sum += f(x, y - 1);
	if (y != N - 1 && map[x][y + 1] < map[x][y]) sum += f(x, y + 1);

	return dp[x][y] = sum;
}