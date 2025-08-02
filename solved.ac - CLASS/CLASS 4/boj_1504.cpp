#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 801, INF = 1e9;
vector<pii> graph[MAXN];
int dist[MAXN];
int N, E;
int v1, v2;

ll dijkstra(int start, int end)
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
	return dist[end];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> E;
	while(E--)
	{
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}
	cin >> v1 >> v2;

	ll path1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
	ll path2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
	if(path1 >= INF && path2 >= INF) cout << -1;
	else cout << min(path1, path2);
}