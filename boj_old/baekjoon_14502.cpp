#include <iostream>
#include <vector>
using namespace std;

int N, M, mx{ 0 };
typedef pair<int, int> pii;
int grid[8][8];
vector<pii> virus;
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

void infect(int, int);

int main()
{
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 2) virus.push_back({ i, j });
		}
	}

	for (int a{ 0 }; a < N; a++)
	{
		for (int b{ 0 }; b < M; b++)
		{
			if (grid[a][b] == 0)
			{
				grid[a][b] = 1;
				for (int c{ 0 }; c < N; c++)
				{
					for (int d{ 0 }; d < M; d++)
					{
						if (grid[c][d] == 0)
						{
							grid[c][d] = 1;
							for (int e{ 0 }; e < N; e++)
							{
								for (int f{ 0 }; f < M; f++)
								{
									if (grid[e][f] == 0)
									{
										grid[e][f] = 1;

										for (int i{ 0 }; i < virus.size(); i++)
										{
											auto [x, y] = virus[i];
											infect(x, y);
										}

										int cnt{ 0 };
										for (int i{ 0 }; i < N; i++)
										{
											for (int j{ 0 }; j < M; j++)
											{
												if (grid[i][j] == -1) grid[i][j] = 0;
												else if (grid[i][j] == 0) cnt++;
											}
										}
										mx = max(mx, cnt);

										grid[e][f] = 0;
									}
								}
							}
							grid[c][d] = 0;
						}
					}
				}
				grid[a][b] = 0;
			}
		}
	}

	cout << mx;
}

void infect(int x, int y)
{
	int p{ x }, q{ y };
	for (int i{ 0 }; i < 4; i++)
	{
		p = x + dir[0][i]; q = y + dir[1][i];
		if (p >= 0 && p < N && q >= 0 && q < M)
		{
			if (grid[p][q] == 0)
			{
				grid[p][q] = -1;
				infect(p, q);
			}
		}
	}
}