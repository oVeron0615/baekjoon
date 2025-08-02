#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MX = 1e9;
	const int SZ = 1001;
	int cost[SZ][4];
	int dp[SZ][4];

	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=3; j++)
		{
			cin >> cost[i][j];
		}
	}

	fill(&dp[0][0], &dp[0][0] + SZ * 4, MX);
	for(int i=1; i<=3; i++) dp[1][i] = cost[1][i];
	
	for(int i=2; i<=N; i++)
	{
		for(int j=1; j<=3; j++)
		{
			for(int k=1; k<=3; k++)
			{
				if(k == j) continue;
				dp[i][j] = min(dp[i][j], dp[i-1][k]);
			}
			dp[i][j] += cost[i][j];
		}
	}

	int ans = MX;
	for(int i=1; i<=3; i++) ans = min(ans, dp[N][i]);
	cout << ans;
}