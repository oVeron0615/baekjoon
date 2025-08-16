#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 500, INF = 1e9;
int N, M;
int S, D;
int graph[MAXN][MAXN], rgraph[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];

void dijkstra()
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[S] = 0; pq.push({dist[S], S});
	while(!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if(dist[u] < du) continue;

		for(int v=0; v<N; v++)
		{
			int dv = graph[u][v];
			if(dv == 0) continue;
			if(dist[v] > du + dv)
			{
				dist[v] = du + dv;
				pq.push({dist[v], v});
			}
		}
	}
}

void DFS(int u)
{
	vis[u] = true;
	for(int v=0; v<N; v++)
	{
		if(!rgraph[u][v]) continue;
		if(dist[u] == dist[v] + rgraph[u][v]) 
		{
			graph[v][u] = 0;
			if(vis[v]) continue;
			DFS(v);
		}
	}
}

void solve()
{
	fill(&dist[0], &dist[0] + MAXN, INF);
	dijkstra();
	DFS(D);
	fill(&dist[0], &dist[0] + MAXN, INF);
	dijkstra();
	
	if(dist[D] == INF) cout << -1 << "\n";
	else cout << dist[D] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(true)
	{
		memset(vis, false, sizeof(vis));
		memset(graph, 0, sizeof(graph));
		memset(rgraph, 0, sizeof(rgraph));

		cin >> N >> M;
		if(N == 0 && M == 0) break;

		cin >> S >> D;
		while(M--)
		{
			int U, V, P; cin >> U >> V >> P;
			graph[U][V] = P, rgraph[V][U] = P;
		}

		solve();
	}
}