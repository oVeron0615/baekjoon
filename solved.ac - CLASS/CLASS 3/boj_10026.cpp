#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 101;
char color[SZ][SZ];
bool vis[SZ][SZ];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int N;
char nowColor;

void DFS(int x, int y, int a)
{
	vis[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(1 <= nx && nx <= N && 1 <= ny && ny <= N)
		{
			if(vis[nx][ny]) continue;
			if(a == 0 && color[x][y] != color[nx][ny]) continue;
			if(a == 1 && (color[x][y] == 'B' ^ color[nx][ny] == 'B')) continue;
			DFS(nx, ny, a);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> color[i][j];
		}
	}

	for (int a = 0; a < 2; a++)
	{
		fill(&vis[0][0], &vis[0][0] + SZ * SZ, false);
		int ans = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (vis[i][j]) continue;
				DFS(i, j, a); ans++;
			}
		}

		cout << ans << " ";
	}
}