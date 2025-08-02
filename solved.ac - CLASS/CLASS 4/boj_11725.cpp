#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 100001;
vector<int> graph[SZ];
bool vis[SZ];
int N;
int ans[SZ];

void DFS(int p, int u)
{
	ans[u] = p;
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(u, v);
	}
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

	DFS(0, 1);
	for(int i=2; i<=N; i++) cout << ans[i] << "\n";
}