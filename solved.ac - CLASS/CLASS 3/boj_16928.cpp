#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int SZ = 101;
	int ladder[SZ] = {}, snake[SZ] = {};
	bool vis[SZ] = {};
	int dist[SZ];

	int N, M; cin >> N >> M;
	while(N--)
	{
		int x, y; cin >> x >> y;
		ladder[x] = y;
	}
	while(M--)
	{
		int u, v; cin >> u >> v;
		snake[u] = v;
	}

	queue<int> qu;
	qu.push(1); vis[1] = true; dist[1] = 0;
	while(!qu.empty())
	{
		int u = qu.front(); qu.pop();
		if(u == 100)
		{
			cout << dist[u];
			return 0;
		}

		for(int i=1; i<=6; i++)
		{
			int v;
			if(ladder[u + i]) v = ladder[u + i];
			else if(snake[u + i]) v = snake[u + i];
			else v = u + i;

			if(v > 100 || vis[v]) continue;
			qu.push(v); vis[v] = true; dist[v] = dist[u] + 1;
		}
	}
}