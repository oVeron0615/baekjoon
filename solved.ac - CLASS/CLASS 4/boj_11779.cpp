#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1001, INF = 1e9;
	vector<pii> graph[MAXN];
	int dist[MAXN];
	fill(&dist[0], &dist[0] + MAXN, INF);
	int prev[MAXN];

	int n, m; cin >> n >> m;
	while(m--)
	{
		int u, v, d; cin >> u >> v >> d;
		graph[u].push_back({d, v});
	}
	int S, E; cin >> S >> E;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[S] = 0;
	pq.push({dist[S], S});
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
				prev[v] = u;
			}
		}
	}

	vector<int> path;
	int node = E;
	while(node != S)
	{
		path.push_back(node);
		node = prev[node];
	}
	path.push_back(node);
	reverse(path.begin(), path.end());

	cout << dist[E] << "\n" << path.size() << "\n";
	for(int p : path) cout << p << " ";
}