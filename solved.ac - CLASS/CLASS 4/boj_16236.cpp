#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct status
{
	int x, y;
	int size = 2;
	int cnt = 0;
};

const int MAXN = 20, INF = 1e9;
int board[MAXN][MAXN];
int dir[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
int N;
status shark;
int ans = 0;
int k;

bool BFS()
{
	int dist[MAXN][MAXN];
	fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, INF);
	dist[shark.x][shark.y] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({dist[shark.x][shark.y], shark.x * N + shark.y});

	while(!pq.empty())
	{
		auto [d, xy] = pq.top(); pq.pop();
		int x = xy/N, y = xy%N;

		if(0 < board[x][y] && board[x][y] < shark.size)
		{
			shark.x = x, shark.y = y;
			board[x][y] = 0;
			if(++shark.cnt == shark.size) shark.cnt = 0, shark.size++;
			ans += dist[x][y];
			return true;
		}

		for(int i=0; i<4; i++)
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];

			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(dist[nx][ny] != INF || board[nx][ny] > shark.size) continue;

			dist[nx][ny] = dist[x][y] + 1;
			pq.push({dist[nx][ny], nx * N + ny});
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 9) 
			{
				shark.x = i, shark.y = j;
				board[i][j] = 0;
			}
		}
	}

	while(BFS());
	cout << ans;
}