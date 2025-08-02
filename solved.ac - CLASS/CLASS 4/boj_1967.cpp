#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10001;
vector<pii> graph[MAXN];
bool vis[MAXN];
int mxDist, mxNode;

void DFS(int u, int du)
{
	vis[u] = true;
	for(auto [dv, v] : graph[u])
	{
		if(vis[v]) continue;
		DFS(v, du + dv);
	}
	if(mxDist < du) mxDist = du, mxNode = u;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for(int i=1; i<n; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
	}

	fill(&vis[0], &vis[0] + MAXN, false); mxDist = 0;
	DFS(1, 0);
	fill(&vis[0], &vis[0] + MAXN, false); mxDist = 0;
	DFS(mxNode, 0);
	cout << mxDist;
}