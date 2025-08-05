#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXV = 10001;
	vector<pii> graph[MAXV];
	bool vis[MAXV] = {};
	int V, E; cin >> V >> E;

	while(E--)
	{
		int A, B, C; cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 1});

	int ans = 0;
	while(!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if(vis[u]) continue;

		vis[u] = true;
		for(auto [dv, v] : graph[u])
		{
			if(vis[v]) continue;
			pq.push({dv, v});
		}

		ans += du;
	}
	cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 10001;
vector<tuple<int, int, int>> edge;
int V, E;
int par[MAXV], height[MAXV];

int Find(int u)
{
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

void Union(int u, int v)
{
	u = Find(u), v = Find(v);
	if(height[u] < height[v]) swap(u, v);
	par[v] = u;
	if(height[u] == height[v]) height[u]++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;
	while(E--)
	{
		int A, B, C; cin >> A >> B >> C;
		edge.push_back({C, A, B});
	}
	sort(edge.begin(), edge.end());

	for(int i=1; i<=V; i++) par[i] = i;
	
	int ans = 0;
	for(auto [d, u, v] : edge)
	{
		if(Find(u) == Find(v)) continue;
		Union(u, v);
		ans += d;
	}
	cout << ans;
}
*/