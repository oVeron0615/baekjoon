#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
vector<int> graph[MAXN];
int cache[MAXN];
int depth[MAXN];
int n;
int ans;

void DFS(int u, int d)
{
	cache[u] = 1, depth[u] = d;
	for(int v : graph[u])
	{
		if(cache[v] == 1) ans -= d - depth[v] + 1;
		if(cache[v] == 0) DFS(v, d+1);
	}
	cache[u] = 2;
}

void solve()
{
	fill(&graph[0], &graph[0] + MAXN, vector<int>());
	fill(&cache[0], &cache[0] + MAXN, 0);
	fill(&depth[0], &depth[0] + MAXN, 0);

	cin >> n;
	for(int u=1; u<=n; u++)
	{
		int v; cin >> v;
		graph[u].push_back(v);
	}

	ans = n;
	for(int i=1; i<=n; i++)
		if(cache[i] == 0) DFS(i, 0);
	
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}