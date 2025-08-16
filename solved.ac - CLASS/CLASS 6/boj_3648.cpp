#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2001;
int n, m;
vector<int> graph[SZ], rgraph[SZ];
bool vis[SZ];
stack<int> st;
int SCC_num[SZ];
int SCC_cnt = 0;

void init()
{
	for(int i=1; i<=n*2; i++) graph[i].clear(), rgraph[i].clear();
	memset(vis, false, sizeof(vis));
	SCC_cnt = 0;
}

int NOT(int u) { return u <= n ? u + n : u - n; }

void DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(v);
	}
	st.push(u);
}

void rDFS(int u)
{
	SCC_num[u] = SCC_cnt;
	vis[u] = true;
	for(int v : rgraph[u])
	{
		if(vis[v]) continue;
		rDFS(v);
	}
}

void solve()
{
	init();

	while(m--)
	{
		int a, b; cin >> a >> b;
		if(a < 0) a = -a + n;
		if(b < 0) b = -b + n;
		graph[NOT(a)].push_back(b), graph[NOT(b)].push_back(a);
		rgraph[b].push_back(NOT(a)), rgraph[a].push_back(NOT(b));
	}
	graph[1+n].push_back(1);
	rgraph[1].push_back(1+n);

	for(int u=1; u<=n*2; u++)
	{
		if(vis[u]) continue;
		DFS(u);
	}

	memset(vis, false, sizeof(vis));
	while(!st.empty())
	{
		int u = st.top(); st.pop();
		if(vis[u]) continue;

		++SCC_cnt;
		rDFS(u);
	}

	for(int u=1; u<=n; u++)
	{
		if(SCC_num[u] == SCC_num[NOT(u)])
		{
			cout << "no\n";
			return;
		}
	}
	cout << "yes\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(cin >> n >> m) solve();
}