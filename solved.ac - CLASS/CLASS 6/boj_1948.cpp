#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10'001;
int n, m;
vector<pii> graphf[MAXN], graphr[MAXN];
bool vis[MAXN];
int S, E;
stack<int> st;
int dist[MAXN];
int ans = 0;

void DFS(int u)
{
	vis[u] = true;
	for(auto [d, v] : graphf[u])
	{
		if(vis[v]) continue;
		DFS(v);
	}
	st.push(u);
}

void track(int u)
{
	vis[u] = true;
	for(auto [d, v] : graphr[u])
	{
		if(dist[u] == dist[v] + d)
		{
			ans++;
			if(vis[v]) continue;
			track(v);
		} 
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	while(m--)
	{
		int u, v, d; cin >> u >> v >> d;
		graphf[u].push_back({d, v});
		graphr[v].push_back({d, u});
	}
	cin >> S >> E;

	DFS(S);

	while(!st.empty())
	{
		int u = st.top(); st.pop();
		for(auto [d, v] : graphf[u])
			if(dist[v] < dist[u] + d) dist[v] = dist[u] + d;
	}

	memset(vis, false, sizeof(vis));
	track(E);

	cout << dist[E] << "\n" << ans;
}