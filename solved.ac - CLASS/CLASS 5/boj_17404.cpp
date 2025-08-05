#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int INF = 1e9, SZ = 1000;
	int cost[SZ][3];
	int dp[SZ][3];

	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin >> cost[i][j];
		}
	}

	int ans = INF;
	for(int first_color=0; first_color<3; first_color++)
	{
		fill(&dp[0][0], &dp[0][0] + SZ * 3, INF);
		dp[0][first_color] = cost[0][first_color];

		for(int i=1; i<N; i++)
		{
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
		}

		for(int last_color=0; last_color<3; last_color++) 
		{
			if(first_color == last_color) continue;
			ans = min(ans, dp[N-1][last_color]);
		}
	}
	cout << ans;
}