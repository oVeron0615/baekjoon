#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 16, INF = 1e9;
	int W[MAXN][MAXN];

	int N; cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> W[i][j];
	
	int dp[MAXN][1 << MAXN];
	fill(&dp[0][0], &dp[0][0] + MAXN * (1 << MAXN), INF);
	dp[0][1] = 0;

	for(int k=1; k<(1 << N); k++)
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(W[j][i] == 0 || k & (1 << i)) continue;
				dp[i][k | (1 << i)] = min(dp[i][k | (1 << i)], dp[j][k] + W[j][i]);
			}
		}
	}

	int ans = INF;
	for(int i=1; i<N; i++)
	{
		if(W[i][0] == 0) continue;
		ans = min(ans, dp[i][(1 << N) - 1] + W[i][0]);
	}
	cout << ans;
}