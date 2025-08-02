#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20001, INF = 1e9;
vector<pii> graph[MAXN];
int dist[MAXN];
int V, E;
int K;

void dijkstra(int start, int end)
{
	fill(&dist[0], &dist[0] + MAXN, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0; pq.push({dist[start], start});
	while(!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if(du > dist[u]) continue;

		for(auto [dv, v] : graph[u])
		{
			if(dist[v] > du + dv)
			{
				dist[v] = du + dv;
				pq.push({dist[v], v});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;
	cin >> K;
	while(E--)
	{
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}

	dijkstra(K, V);
	for(int i=1; i<=V; i++)
	{
		if(dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}