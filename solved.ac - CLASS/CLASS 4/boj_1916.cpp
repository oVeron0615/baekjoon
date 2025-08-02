#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1001;
	vector<pii> graph[MAXN];
	int dist[MAXN];

	int N, M; cin >> N >> M;
	while(M--)
	{
		int u, v, d; cin >> u >> v >> d;
		graph[u].push_back({v, d});
	}

	int S, E; cin >> S >> E;
	fill(&dist[0], &dist[0] + MAXN, 1e9);
	dist[S] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({dist[S], S});

	while(!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if(du > dist[u]) continue;

		for(auto [v, dv] : graph[u])
		{
			if(dist[v] > du + dv)
			{
				dist[v] = du + dv;
				pq.push({dist[v], v});
			}
		}
	}

	cout << dist[E];
}