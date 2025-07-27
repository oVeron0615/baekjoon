#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

typedef array<int, 4> a;
int N, M;
bool wall[1001][1001];
bool vis0[1001][1001], vis1[1001][1001];
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
queue<a> qu;
bool check{};

int main()
{
	cin >> N >> M;
	for (int i{ 1 }; i <= N; i++)
	{
		for (int j{ 1 }; j <= M; j++)
		{
			char c; cin >> c;
			wall[i][j] = c - '0';
		}
	}

	qu.push({ 1, 1, 1, 0 });
	vis0[0][0] = true;
	while (!qu.empty())
	{
		int x = qu.front()[0], y = qu.front()[1],
			l = qu.front()[2], w = qu.front()[3];
		qu.pop();

		if (x == N && y == M)
		{
			cout << l;
			check = true;
			break;
		}

		for (int i{ 0 }; i < 4; i++)
		{
			int p = x + dir[0][i], q = y + dir[1][i];
			if (p >= 1 && p <= N && q >= 1 && q <= M)
			{
				if (w == 0 && vis0[p][q]) continue;
				else if (w == 1 && vis1[p][q]) continue;

				if (w == 0)
				{
					if (wall[p][q])
					{
						qu.push({ p, q, l + 1, 1 });
						vis1[p][q] = true;
					}
					else
					{
						qu.push({ p, q, l + 1, 0 });
						vis0[p][q] = true;
					}
				}
				else
				{
					if (!wall[p][q])
					{
						qu.push({ p, q, l + 1, 1 });
						vis1[p][q] = true;
					}
				}
			}
		}
	}

	if (!check) cout << -1;
}