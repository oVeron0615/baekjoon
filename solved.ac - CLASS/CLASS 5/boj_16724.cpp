#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1001;
char board[SZ][SZ];
int cache[SZ][SZ];
int N, M;
int ans = 0;

void DFS(int x, int y)
{
	cache[x][y] = 1;

	int nx, ny;
	switch(board[x][y])
	{
		case 'U': nx = x-1, ny = y; break;
		case 'D': nx = x+1, ny = y; break;
		case 'L': nx = x, ny = y-1; break;
		case 'R': nx = x, ny = y+1; break;
	}

	if(cache[nx][ny] == 1) ans++;
	if(cache[nx][ny] == 0) DFS(nx, ny);

	cache[x][y] = 2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin >> board[i][j];

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			if(cache[i][j] == 0) DFS(i, j);
	cout << ans;
}