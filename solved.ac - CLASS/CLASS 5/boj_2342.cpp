#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int force(int u, int v)
{
	if(u == v) return 1;
	if(u == 0) return 2;
	if(abs(u-v) == 2) return 4;
	return 3;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int SZ = 100001, INF = 1e9;
	int dp[SZ][25];
	fill(&dp[0][0], &dp[0][0] + SZ * 25, INF);
	dp[0][0] = 0;

	int order[SZ];
	int idx = 1;
	while(true)
	{
		int o; cin >> o;
		if(o == 0) break;
		order[idx++] = o;
	}

	for(int k=1; k<idx; k++)
	{
		for(int i=0; i<25; i++)
		{
			for(int j=0; j<25; j++)
			{
				int x = i/5, y = i%5;
				int px = j/5, py = j%5;
				if(x == y) continue;
				if(px == x && y == order[k]) dp[k][i] = min(dp[k][i], dp[k-1][j] + force(py, y));
				if(py == y && x == order[k]) dp[k][i] = min(dp[k][i], dp[k-1][j] + force(px, x));
			}
		}
	}

	int ans = INF;
	for(int i=0; i<25; i++) ans = min(ans, dp[idx-1][i]);
	cout << ans;
}