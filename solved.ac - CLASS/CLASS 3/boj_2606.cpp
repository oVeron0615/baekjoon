#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> graph[101];
bool vis[101] = {};

void DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int V, E; cin >> V >> E;
	for(int i=1; i<=E; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	DFS(1);

	int ans = 0;
	for(int i=2; i<=V; i++)
		if(vis[i]) ans++;
	cout << ans;
}