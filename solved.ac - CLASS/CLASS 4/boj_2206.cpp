#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int SZ = 1000, INF = 1e9;
	int N, M; cin >> N >> M;
	char board[SZ][SZ];
	int dist[2][SZ][SZ];
	fill(&dist[0][0][0], &dist[0][0][0] + 2 * SZ * SZ, INF);
	int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<pii> qu;
	dist[0][0][0] = 1, qu.push({0, 0});
	while(!qu.empty())
	{
		auto [isBreak, u] = qu.front(); qu.pop();
		int x = u/M, y = u%M;
		for(int i=0; i<4; i++)
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];

			if(0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if(isBreak)
				{
					if(board[nx][ny] == '0' && dist[1][nx][ny] == INF)
					{
						dist[1][nx][ny] = dist[1][x][y] + 1;
						qu.push({1, nx*M + ny});
					}
				}
				else
				{
					if(board[nx][ny] == '0' && dist[0][nx][ny] == INF)
					{
						dist[0][nx][ny] = dist[0][x][y] + 1;
						qu.push({0, nx*M + ny});
					}
					else if(board[nx][ny] == '1' && dist[1][nx][ny] == INF)
					{
						dist[1][nx][ny] = dist[0][x][y] + 1;
						qu.push({1, nx*M + ny});
					}
				}
			}
		}
	}

	int ans = min(dist[0][N-1][M-1], dist[1][N-1][M-1]);
	if(ans == INF) cout << -1;
	else cout << ans;
}