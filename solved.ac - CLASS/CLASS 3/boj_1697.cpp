#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100000;
	int N, K; cin >> N >> K;
	bool vis[MAXN + 1] = {};
	int dist[MAXN + 1];

	queue<int> qu;
	qu.push(N); vis[N] = true; dist[N] = 0;
	while(!qu.empty())
	{
		int u = qu.front(); qu.pop();
		if(u == K)
		{
			cout << dist[u];
			return 0;
		}

		int nx[3] = {u + 1, u - 1, u * 2};
		for(int v : nx)
		{
			if(v >= 0 && v <= MAXN && !vis[v])
				qu.push(v), vis[v] = true, dist[v] = dist[u] + 1;
		}
	}
}