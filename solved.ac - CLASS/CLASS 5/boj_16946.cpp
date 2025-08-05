#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1000;
int N, M; 
char board[SZ][SZ];
bool vis[SZ][SZ];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int par[SZ * SZ], height[SZ * SZ];
int setSize[SZ * SZ];

int Find(int u)
{
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

void Union(int u, int v)
{
	u = Find(u), v = Find(v);
	if(u == v) return;

	if(height[u] < height[v]) swap(u, v);
	par[v] = u;
	if(height[u] == height[v]) height[u]++;
	setSize[u] += setSize[v];
}

void DFS(int x, int y)
{
	vis[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if(board[nx][ny] == '1' || vis[nx][ny]) continue;

		DFS(nx, ny);
		Union(x*M+y, nx*M+ny);
	}
}

int Sum(int x, int y)
{
	set<int> sets;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if(board[nx][ny] == '1') continue;

		sets.insert(Find(nx*M+ny));
	}

	int sum = 1;
	for(int s : sets) sum += setSize[s];
	return sum % 10;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> board[i][j];
	
	for(int i=0; i<N*M; i++) par[i] = i;
	fill(&setSize[0], &setSize[0] + SZ * SZ, 1);
		
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(board[i][j] == '0' && !vis[i][j]) DFS(i, j);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(board[i][j] == '0') cout << 0;
			else cout << Sum(i, j);
		}
		cout << "\n";
	}
}