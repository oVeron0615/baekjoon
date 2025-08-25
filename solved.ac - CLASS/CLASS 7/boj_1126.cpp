#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51, MAXH = 500'000, INF = 1e9;
int N;
int block[MAXH];
int dp[MAXN][MAXH];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> block[i];

	fill(&dp[0][0], &dp[0][0] + MAXN * MAXH, -INF);
	dp[0][0] = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<=MAXH/2; j++)
		{
			dp[i][j] = max(dp[i-1][j], dp[i-1][j + block[i]]);
			if(j > block[i]) dp[i][j] = max(dp[i][j], dp[i-1][j - block[i]] + block[i]);
			else dp[i][j] = max(dp[i][j], dp[i-1][block[i] - j] + j);
		}
	}

	if(dp[N][0] <= 0) cout << -1;
	else cout << dp[N][0];
} 