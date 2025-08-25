#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100, MAXM = 100;
const int SZ = MAXN * MAXM * 2;
const int INF = 1e9;
int N, M;
char board[MAXN][MAXM];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

struct edge
{
	int v, cap, rIdx;
};

vector<edge> graph[SZ];
map<pii, int> cap;
int S, T;

bool vis[SZ];

void makeGraph(int u, int v, int cap)
{
	edge uv = {v, cap, int(graph[v].size())};
	edge vu = {u, 0, int(graph[u].size())};
	graph[u].push_back(uv);
	graph[v].push_back(vu);
}

int DFS(int u, int minCap)
{
	vis[u] = true;
	if(u == T) return minCap;

	for(int i=0; i<graph[u].size(); i++)
	{
		auto [v, cap, rIdx] = graph[u][i];
		if(vis[v] || cap == 0) continue;

		int f = DFS(v, min(cap, minCap));
		if(f)
		{
			graph[u][i].cap -= f; graph[v][rIdx].cap += f;
			return f;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 'K') S = i * M + j;
			if(board[i][j] == 'H') T = i * M + j;
		}	
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(board[i][j] == '#') continue;

			int u = i * M + j;
			makeGraph(u, u + N*M, (u == S || u == T ? INF : 1));

			for(int d=0; d<4; d++)
			{
				int ni = i + dir[0][d];
				int nj = j + dir[1][d];

				if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
				if(board[ni][nj] == '#') continue;

				int v = ni * M + nj;
				makeGraph(u + N*M, v, INF); makeGraph(v + N*M, u, INF);
			}
		}
	}

	int ans = 0;
	while(true)
	{
		memset(vis, false, sizeof(vis));

		int f = DFS(S, INF);
		if(f == 0) break;
		ans += f;
	}

	if(ans == INF) cout << -1;
	else cout << ans;
}