#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, SP = 17;
vector<pii> graph[MAXN];
bool vis[MAXN];
int dist[MAXN], par[SP][MAXN];
int ant[MAXN];
int n;

void DFS(int u, int p, int d)
{
	vis[u] = true, par[0][u] = p, dist[u] = d;
	for(auto [dv, v] : graph[u])
	{
		if(vis[v]) continue;
		DFS(v, u, d + dv);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=1; i<=n; i++) cin >> ant[i];
	for(int i=1; i<n; i++)
	{
		int u, v, d; cin >> u >> v >> d;
		graph[u].push_back({d, v});
		graph[v].push_back({d, u});
	}

	DFS(1, 0, 0);

	for(int i=1; i<SP; i++)
		for(int j=1; j<=n; j++)
			par[i][j] = par[i-1][par[i-1][j]];
	
	for(int node=1; node<=n; node++)
	{
		int u = node;
		for(int i=SP-1; i>=0; i--)
		{
			int p = par[i][u] == 0 ? 1 : par[i][u];
			if(ant[node] >= dist[u] - dist[p])
			{
				ant[node] -= dist[u] - dist[p];
				u = p;
			}
		}

		cout << u << "\n";
	}
}