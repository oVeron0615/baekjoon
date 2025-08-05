#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 21, MAXC = 1001, INF = 1e9;
int dp[MAXN][MAXC];
int cost[MAXN], val[MAXN];
int N, C;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> C >> N;
	for(int i=1; i<=N; i++) cin >> cost[i] >> val[i];

	fill(&dp[0][0], &dp[0][0] + MAXN * MAXC, INF);
	dp[0][0] = 0;

	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<=C; j++)
		{
			int k = 0;
			while(val[i]*k < j)
			{
				dp[i][j] = min(dp[i][j], dp[i-1][j-val[i]*k] + cost[i]*k);
				k++;
			}
			dp[i][j] = min(dp[i][j], dp[i-1][0] + cost[i]*k);
		}
	}
	cout << dp[N][C];
}