#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1001;
vector<int> graph[SZ];
bool vis[SZ];

void DFS(int u)
{
	cout << u << " ";
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

	int N, M, V; cin >> N >> M >> V;
	while(M--)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1; i<=N; i++) 
		sort(graph[i].begin(), graph[i].end());

	fill(&vis[0], &vis[0] + SZ, false);
	DFS(V);
	cout << "\n";

	fill(&vis[0], &vis[0] + SZ, false);
	queue<int> qu;
	qu.push(V); vis[V] = true;
	while(!qu.empty())
	{
		int u = qu.front(); qu.pop();
		cout << u << " ";

		for(int v : graph[u])
		{
			if(vis[v]) continue;
			qu.push(v); vis[v] = true;
		}
	}
}