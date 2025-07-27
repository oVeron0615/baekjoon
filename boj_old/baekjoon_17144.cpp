#include <iostream>
using namespace std;

int R, C, T;
int room[50][50];
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int a{ -1 }, b{ -1 };

void diffusion();
void cycle1();
void cycle2();

int main()
{
	cin >> R >> C >> T;
	for (int i{ 0 }; i < R; i++)
	{
		for (int j{ 0 }; j < C; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == -1)
			{
				if (a == -1) a = i;
				else b = i;
			}
		}
	}

	for (int t{ 1 }; t <= T; t++)
	{
		diffusion();
		cycle1();
		cycle2();
	}
	
	int cnt{ 0 };
	for (int i{ 0 }; i < R; i++)
	{
		for (int j{ 0 }; j < C; j++)
		{
			if (room[i][j] != -1) cnt += room[i][j];
		}
	}
	cout << cnt;
}

void diffusion()
{
	int dust[50][50] = {};
	for (int i{ 0 }; i < R; i++)
	{
		for (int j{ 0 }; j < C; j++)
		{
			int plus = room[i][j] / 5;
			for (int k{ 0 }; k < 4; k++)
			{
				int x{ i + dir[0][k] }, y{ j + dir[1][k] };
				if (x >= 0 && x < R && y >= 0 && y < C && room[x][y] != -1)
				{
					dust[x][y] += plus;
					room[i][j] -= plus;
				}
			}
		}
	}

	for (int i{ 0 }; i < R; i++)
	{
		for (int j{ 0 }; j < C; j++)
		{
			if (room[i][j] != -1) room[i][j] += dust[i][j];
		}
	}
}

void cycle1()
{
	for (int i{ a - 1 }; i >= 1; i--)
	{
		room[i][0] = room[i - 1][0];
	}
	for (int i{ 0 }; i < C - 1; i++)
	{
		room[0][i] = room[0][i + 1];
	}
	for (int i{ 0 }; i < a; i++)
	{
		room[i][C - 1] = room[i + 1][C - 1];
	}
	for (int i{ C - 1 }; i >= 2; i--)
	{
		room[a][i] = room[a][i - 1];
	}
	room[a][1] = 0;
}

void cycle2()
{
	for (int i{ b + 1 }; i < R - 1; i++)
	{
		room[i][0] = room[i + 1][0];
	}
	for (int i{ 0 }; i < C - 1; i++)
	{
		room[R - 1][i] = room[R - 1][i + 1];
	}
	for (int i{ R - 1 }; i >= b + 1; i--)
	{
		room[i][C - 1] = room[i - 1][C - 1];
	}
	for (int i{ C - 1 }; i >= 2; i--)
	{
		room[b][i] = room[b][i - 1];
	}
	room[b][1] = 0;
}