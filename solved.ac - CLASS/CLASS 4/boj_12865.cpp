#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 101, MAXK = 100001;
	int dp[MAXN][MAXK] = {};
	pii item[MAXN];

	int N, K; cin >> N >> K;
	for(int i=1; i<=N; i++)
	{
		int W, V; cin >> W >> V;
		item[i] = {W, V};
	}

	for(int i=1; i<=N; i++)
	{
		auto [W, V] = item[i];
		for(int j=0; j<=K; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j >= W) dp[i][j] = max(dp[i][j], dp[i-1][j-W] + V);
		}
	}

	cout << dp[N][K];
}