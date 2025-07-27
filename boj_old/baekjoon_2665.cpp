#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int n;
char rooms[51][51];
bool vis[51][51];
queue<pii> qu;
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int ans{0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i{1}; i <= n; i++)
		for (int j{1}; j <= n; j++)
			cin >> rooms[i][j];

	qu.push({1, 1});
	vis[1][1] = true;
	while (true)
	{
		queue<pii> quTmp; // 갈 수 없는 영역을 저장한 queue

		while (!qu.empty())
		{
			auto [cx, cy] = qu.front();
			qu.pop();

			for (int i{0}; i < 4; i++)
			{
				int nx = cx + dir[0][i];
				int ny = cy + dir[1][i];

				if (nx == n && ny == n)
				{
					cout << ans << "\n";
					return 0;
				}

				if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
				{
					if (!vis[nx][ny])
					{
						if (rooms[nx][ny] == '1')
							qu.push({nx, ny});
						else
							quTmp.push({nx, ny});
						vis[nx][ny] = true;
					}
				}
			}
		}

		qu = quTmp;
		ans++;
	}
}