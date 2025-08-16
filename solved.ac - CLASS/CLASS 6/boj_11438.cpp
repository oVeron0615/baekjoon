#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, SP = 17;
int N, M;
vector<int> graph[MAXN];
int par[SP][MAXN], lv[MAXN];
bool vis[MAXN];

void DFS(int u, int p, int l)
{
	vis[u] = true, par[0][u] = p, lv[u] = l;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(v, u, l+1);
	}
}

int LCA(int u, int v)
{
	if(lv[u] < lv[v]) swap(u, v);

	int d = lv[u] - lv[v];
	for(int i=0; i<SP; i++)
		if(d & (1 << i)) u = par[i][u];
	
	if(u == v) return u;

	for(int i=SP-1; i>=0; i--)
		if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
	
	return par[0][u];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<N; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1, 0, 1);

	for(int i=1; i<SP; i++)
		for(int j=1; j<=N; j++)
			par[i][j] = par[i-1][par[i-1][j]];
	
	cin >> M;
	while(M--)
	{
		int u, v; cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}
}