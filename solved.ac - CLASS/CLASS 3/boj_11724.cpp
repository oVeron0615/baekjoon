#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> graph[1001];
bool vis[1001] = {};

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

	int N, M; cin >> N >> M;
	while(M--)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		if(vis[i]) continue;
		DFS(i); ans++;
	}
	cout << ans;
}