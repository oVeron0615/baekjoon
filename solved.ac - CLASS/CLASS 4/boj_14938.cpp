#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 101, INF = 1e9;
	int n, m, r; cin >> n >> m >> r;
	int area[MAXN];
	int dist[MAXN][MAXN];

	fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, INF);
	for(int i=1; i<=n; i++) dist[i][i] = 0;

	for(int i=1; i<=n; i++) cin >> area[i];
	while(r--)
	{
		int a, b, l; cin >> a >> b >> l;
		dist[a][b] = dist[b][a] = l;
	}

	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		int sum = 0;
		for(int j=1; j<=n; j++)
		{
			if(dist[i][j] <= m) sum += area[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;
}