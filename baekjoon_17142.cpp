#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, M;
int lab[51][51];
int labSize{0};
vector<pii> virus;
vector<pii> initVirus;
queue<pii> qu;
bool vis[51][51];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int ans = inf;

void solve()
{
	while (!qu.empty())
		qu.pop();
	for (int i{1}; i <= N; i++)
		for (int j{1}; j <= N; j++)
			vis[i][j] = false;

	for (pii v : initVirus)
	{
		qu.push(v);
		auto [x, y] = v;
		vis[x][y] = true;
	}

	int ls = labSize;
	int moveCnt{0};
	while (!qu.empty())
	{
		if (!ls)
			break;
		moveCnt++;

		int size = qu.size();
		while (size--)
		{
			auto [cx, cy] = qu.front();
			qu.pop();

			for (int i{0}; i < 4; i++)
			{
				int nx = cx + dir[0][i];
				int ny = cy + dir[1][i];

				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
				{
					if (!vis[nx][ny] && lab[nx][ny] != 1)
					{
						qu.push({nx, ny});
						vis[nx][ny] = true;
						if (lab[nx][ny] != 2)
							ls--;
					}
				}
			}
		}
	}

	for (int i{1}; i <= N; i++)
		for (int j{1}; j <= N; j++)
			if (!vis[i][j] && lab[i][j] == 0)
				return;

	ans = min(ans, moveCnt);
}

void virusStart(int idx)
{
	if (initVirus.size() == M)
	{
		solve();
		return;
	}
	if (idx == virus.size())
		return;

	auto [x, y] = virus[idx];

	initVirus.push_back(virus[idx]);
	virusStart(idx + 1);

	initVirus.pop_back();
	virusStart(idx + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i{1}; i <= N; i++)
		for (int j{1}; j <= N; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 2)
				virus.push_back({i, j});
			if (lab[i][j] == 0)
				labSize++;
		}

	virusStart(0);

	if (ans == inf)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}