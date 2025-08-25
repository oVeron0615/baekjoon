#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
int n, m;
vector<int> graph[MAXN];
bool vis[MAXN];
int match[MAXN];

bool DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[match[v]]) continue;
		if(!match[v] || DFS(match[v]))
		{
			match[v] = u;
			return true;
		}
	}
	return false;
}

void solve()
{
	cin >> n >> m;
	memset(match, 0, sizeof(match));
	for(int i=1; i<=n; i++) graph[i].clear();

	while(m--)
	{
		int u, v; cin >> u >> v;
		u++; v++;
		graph[u].push_back(v);
	}

	int ans = 0;
	for(int u=1; u<=n; u++)
	{
		memset(vis, false, sizeof(vis));
		if(DFS(u)) ans++;
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}