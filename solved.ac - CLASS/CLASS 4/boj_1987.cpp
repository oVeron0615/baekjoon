#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 21;
int R, C;
char board[SZ][SZ];
bool vis[26];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int ans = 0;

void DFS(int x, int y, int d)
{
	ans = max(ans, d);
	vis[board[x][y] - 'A'] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];
		
		if(1 <= nx && nx <= R && 1 <= ny && ny <= C)
		{
			if(vis[board[nx][ny] - 'A']) continue;
			DFS(nx, ny, d+1);
		}
	}
	vis[board[x][y] - 'A'] = false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> R >> C;
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			cin >> board[i][j];
		}
	}

	DFS(1, 1, 1);
	cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 21;
int R, C;
char board[SZ][SZ];
int dist[SZ][SZ];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> R >> C;
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<pair<pii, int>> qu;
	dist[1][1] = 1;
	qu.push({{1, 1}, 1 << (board[1][1] - 'A')});
	while(!qu.empty())
	{
		auto [xy, vis] = qu.front(); qu.pop();
		auto [x, y] = xy;
		ans = max(ans, dist[x][y]);

		for(int i=0; i<4; i++)
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];

			if(1 <= nx && nx <= R && 1 <= ny && ny <= C)
			{
				if(vis & (1 << (board[nx][ny] - 'A'))) continue;
				qu.push({{nx, ny}, vis | (1 << (board[nx][ny] - 'A'))});
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	cout << ans;
}
*/