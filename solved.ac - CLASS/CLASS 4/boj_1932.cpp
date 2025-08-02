#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int SZ = 500;
	int tri[SZ][SZ], dp[SZ][SZ];

	int n; cin >> n;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cin >> tri[i][j];
		}
	}

	fill(&dp[0][0], &dp[0][0] + SZ * SZ, 0);
	dp[0][0] = tri[0][0];

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			if(j < i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
			dp[i][j] += tri[i][j];
		}
	}

	int ans = 0;
	for(int i=0; i<n; i++) ans = max(ans, dp[n-1][i]);
	cout << ans;
}