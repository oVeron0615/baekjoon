#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	char maze[101][101];
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin >> maze[i][j];

	int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
	bool vis[101][101] = {};
	int dist[101][101];
	queue<pii> qu;
	qu.push({1, 1}), vis[1][1] = true, dist[1][1] = 1;

	while(!qu.empty())
	{
		auto [x, y] = qu.front(); qu.pop();
		for(int i=0; i<4; i++)
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];

			if(nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				if(vis[nx][ny] || maze[nx][ny] == '0') continue;
				qu.push({nx, ny}), vis[nx][ny] = true, dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	cout << dist[N][M];
}