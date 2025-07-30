#include <bits/stdc++.h>
using namespace std;

#define SIZE 50

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int M, N, K; 
bool isPlanted[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void DFS(int i, int j)
{
	vis[i][j] = true;
	for(int d=0; d<4; d++)
	{
		int ni = i + dir[0][d];
		int nj = j + dir[1][d];
		if(ni >= 0 && ni < M && nj >= 0 && nj < N)
		{
			if(vis[ni][nj] || !isPlanted[ni][nj]) continue;
			DFS(ni, nj);
		}
	}
}

void solve()
{
	fill(&isPlanted[0][0], &isPlanted[0][0] + SIZE * SIZE, false);
	fill(&vis[0][0], &vis[0][0] + SIZE * SIZE, false);

	cin >> M >> N >> K;
	while(K--)
	{
		int X, Y; cin >> X >> Y;
		isPlanted[X][Y] = true;
	}

	int ans = 0;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(vis[i][j] || !isPlanted[i][j]) continue;
			DFS(i, j);
			ans++;
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();	
}