#include <iostream>
using namespace std;

char forest[50][50];
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

int main()
{
	int R, C;
	cin >> R >> C;

	for (int i{ 0 }; i < R; i++)
	{
		for (int j{ 0 }; j < C; j++)
		{
			cin >> forest[i][j];
		}
	}

	int cnt{};
	bool check, reach{};
	while (true)
	{
		check = false;
		for (int i{ 0 }; i < R; i++)
		{
			for (int j{ 0 }; j < C; j++)
			{
				if (forest[i][j] == 'S')
				{
					for (int k{ 0 }; k < 4; k++)
					{
						bool go{ true };
						int a{ i + dir[0][k] }, b{ j + dir[1][k] };
						if (a >= 0 && a < R && b >= 0 && b < C)
						{
							if (forest[a][b] == '.')
							{
								for (int l{ 0 }; l < 4; l++)
								{
									int c{ a + dir[0][l] }, d{ b + dir[1][l] };
									if (c >= 0 && c < R && d >= 0 && d < C)
									{
										if (forest[c][d] == '*')
										{
											go = false;
											break;
										}
									}
								}
								if (go)
								{
									forest[a][b] = 's';
									check = true;
								}
							}
							else if (forest[a][b] == 'D')
							{
								reach = true;
								cnt++;
								break;
							}
						}
					}
				}
				if (reach) break;
			}
			if (reach) break;
		}
		if (reach) break;

		for (int i{ 0 }; i < R; i++)
		{
			for (int j{ 0 }; j < C; j++)
			{
				if (forest[i][j] == 's') forest[i][j] = 'S';
			}
		}

		cnt++;
		if (!check) break;

		for (int i{ 0 }; i < R; i++)
		{
			for (int j{ 0 }; j < C; j++)
			{
				if (forest[i][j] == '*')
				{
					for (int k{ 0 }; k < 4; k++)
					{
						int a{ i + dir[0][k] }, b{ j + dir[1][k] };
						if (a >= 0 && a < R && b >= 0 && b < C)
						{
							if (forest[a][b] == '.' || forest[a][b] == 'S') forest[a][b] = '&';
						}
					}
				}
			}
		}

		for (int i{ 0 }; i < R; i++)
		{
			for (int j{ 0 }; j < C; j++)
			{
				if (forest[i][j] == '&') forest[i][j] = '*';
			}
		}
	}

	if (reach) cout << cnt;
	else cout << "KAKTUS";
}