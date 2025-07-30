#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 101;
bool ans[SZ][SZ] = {};
bool vis[SZ];
bool graph[SZ][SZ];
int N;

void DFS(int u, int s)
{
	vis[u] = true;
	for(int v=1; v<=N; v++)
	{
		if(!graph[u][v]) continue;
		if(s == v) ans[s][v] = true;
		else if(vis[v]) continue;
		ans[s][v] = true; DFS(v, s);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> graph[i][j];
	
	for(int i=1; i<=N; i++)
	{
		fill(&vis[0], &vis[0] + SZ, false);
		DFS(i, i);
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}