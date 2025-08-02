#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1001, INF = 1e9;
	int dist[MAXN][MAXN];
	fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, INF);

	int N, M, X; cin >> N >> M >> X;
	while(M--)
	{
		int u, v, t; cin >> u >> v >> t;
		dist[u][v] = t;
	}
	for(int i=1; i<=N; i++)	dist[i][i] = 0;

	for(int k=1; k<=N; k++)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		ans = max(ans, dist[i][X] + dist[X][i]);
	}
	cout << ans;
}