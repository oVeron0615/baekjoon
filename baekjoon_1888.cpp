#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int n, m;
bool check[100][100];
int wall[100][100];

void f(int, int);

int main()
{
	cin >> n >> m;
	for (int i{ 0 }; i < n; i++)
	{
		for (int j{ 0 }; j < m; j++)
		{
			char c; cin >> c;
			wall[i][j] = c - '0';
		}
	}

	int ans{};
	while (true)
	{
		int cnt{};
		for (int i{ 0 }; i < n; i++)
		{
			for (int j{ 0 }; j < m; j++)
			{
				if (wall[i][j] != 0 && !check[i][j])
				{
					f(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 1) break;

		for (int i{ 0 }; i < n; i++)
		{
			for (int j{ 0 }; j < m; j++)
			{
				int k{ wall[i][j] };
				if (k == 0) continue;

				for (int p{ i - k }; p <= i + k; p++)
				{
					if (p < 0 || p >= n) continue;
					for (int q{ j - k }; q <= j + k; q++)
					{
						if (q < 0 || q >= m) continue;
						if (k > abs(wall[p][q])) wall[p][q] = -k;
					}
				}
			}
		}

		for (int i{ 0 }; i < n; i++)
		{
			for (int j{ 0 }; j < m; j++)
			{
				wall[i][j] = abs(wall[i][j]);
			}
		}

		ans++;
		memset(check, 0, sizeof(check));
	}
	cout << ans;
}

void f(int x, int y)
{
	check[x][y] = true;
	for (int i{ 0 }; i < 4; i++)
	{
		int p{ x + dir[0][i] }, q{ y + dir[1][i] };
		if (p >= 0 && p < n && q >= 0 && q < m)
		{
			if (wall[p][q] != 0 && !check[p][q]) f(p, q);
		}
	}
}