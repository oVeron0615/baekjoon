#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 40'001, SP = 16;
vector<pii> graph[MAXN];
bool vis[MAXN];
int dist[MAXN], par[SP][MAXN], lv[MAXN]; //dist : 루트 노드까지의 거리, par : 부모 노드를 구하는 희소 배열, lv : 노드의 level
int N, M;

void DFS(int u, int p, int d, int l)
{
	vis[u] = true, par[0][u] = p, dist[u] = d, lv[u] = l;
	for(auto [dv, v] : graph[u])
	{
		if(vis[v]) continue;
		DFS(v, u, d + dv, l + 1);
	}
}

int LCA(int u, int v)
{
	if(lv[u] < lv[v]) swap(u, v);

	//두 노드의 level을 맞춘다.
	int d = lv[u] - lv[v];
	for(int i=0; i<SP; i++)
		if(d & (1 << i)) u = par[i][u];
	
	if(u == v) return u; //두 노드가 같다면 return
	
	//다르면, 두 노드의 부모가 같을 때까지 조상을 탐색
	for(int i=SP-1; i>=0; i--)
		if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
	
	return par[0][u]; //두 노드의 부모가 같아졌으므로, 노드의 부모를 return
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<N; i++)
	{
		int u, v, d; cin >> u >> v >> d;
		graph[u].push_back({d, v});
		graph[v].push_back({d, u});
	}

	DFS(1, 0, 0, 1);

	//희소 배열 전처리
	for(int i=1; i<SP; i++)
		for(int j=1; j<=N; j++)
			par[i][j] = par[i-1][par[i-1][j]];
	
	cin >> M;
	while(M--)
	{
		int u, v; cin >> u >> v;
		int p = LCA(u, v);
		cout << dist[u] + dist[v] - 2 * dist[p] << "\n";
		//u, v 간의 거리 = (루트에서 u까지의 거리 - 루트에서 LCA까지의 거리) + (루트에서 v까지의 거리 - 루트에서 LCA까지의 거리)
		// = (루트에서 u까지의 거리 + 루트에서 v까지의 거리 - 2 * 루트에서 LCA까지의 거리
	}
}