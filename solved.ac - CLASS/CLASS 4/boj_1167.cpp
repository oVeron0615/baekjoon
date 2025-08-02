#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
const ll INF = 1e18;
vector<pll> graph[MAXN];
int V;
ll dist[MAXN];
ll mxDist, mxDistIdx;

void DFS(int u)
{
	if(mxDist < dist[u]) mxDist = dist[u], mxDistIdx = u;
	for(auto [d, v] : graph[u])
	{
		if(dist[v] != INF) continue;
		dist[v] = dist[u] + d;
		DFS(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V;
	for(int i=1; i<=V; i++)
	{
		int u; cin >> u;
		while(true)
		{
			int v; cin >> v;
			if(v == -1) break;

			int d; cin >> d;
			graph[u].push_back({d, v});
		}
	}

	fill(&dist[0], &dist[0] + MAXN, INF);
	mxDist = 0, dist[1] = 0; DFS(1);
	fill(&dist[0], &dist[0] + MAXN, INF);
	mxDist = 0, dist[mxDistIdx] = 0; DFS(mxDistIdx);
	cout << mxDist;
}