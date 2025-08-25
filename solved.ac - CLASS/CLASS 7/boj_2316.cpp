#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 810, INF = 1e9;
int N, P;
vector<int> graph[SZ];
int cap[SZ][SZ], fl[SZ][SZ];
bool vis[SZ];
int S = 1, T = 2;

void makeGraph(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int DFS(int u, int minCap)
{
	vis[u] = true;
	if(u == T) return minCap;

	for(int v : graph[u])
	{
		if(vis[v] || cap[u][v] - fl[u][v] == 0) continue;
		
		int res = DFS(v, min(minCap, cap[u][v] - fl[u][v]));
		if(res)
		{
			fl[u][v] += res, fl[v][u] -= res;
			return res;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> P;

	for(int u=1; u<=N; u++)
	{
		makeGraph(u, u+N);
		cap[u][u+N] = (u == 1 || u == 2 ? INF : 1);
	}
	while(P--)
	{
		int u, v; cin >> u >> v;
		makeGraph(u+N, v); makeGraph(v+N, u);
		cap[u+N][v] = cap[v+N][u] = INF; //간선에는 용량이 없으므로 INF 설정
	}

	int ans = 0;
	while(true)
	{
		memset(vis, false, sizeof(vis));

		int f = DFS(S, INF);
		if(f == 0) break;
		ans += f;
	}
	cout << ans;
} 