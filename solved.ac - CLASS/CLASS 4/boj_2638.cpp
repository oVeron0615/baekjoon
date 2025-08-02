#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 101;
int board[SZ][SZ];
int N, M; 
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void DFS(int x, int y)
{
	board[x][y] = -1;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(1 <= nx && nx <= N && 1 <= ny && ny <= M)
		{
			if(board[nx][ny] == 0) DFS(nx, ny);
		}
	}
}

bool melt(int x, int y)
{
	int cnt = 0;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(board[nx][ny] == -1) cnt++;
	}
	
	return cnt >= 2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<pii> qu; qu.push({1, 1});

	int ans = 0;
	while(true)
	{
		bool check = true;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				if(board[i][j] == 1) check = false;
			}
		}
		if(check) break;
		ans++;

		while(!qu.empty())
		{
			auto [x, y] = qu.front(); qu.pop();
			DFS(x, y);
		}

		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				if(board[i][j] == 1)
				{
					if(melt(i, j)) 
					{
						board[i][j] = 0;
						qu.push({i, j});
					}
				}
			}
		}
	}
	cout << ans;
}