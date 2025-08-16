#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MOD = 10'007, SZ = 53;
	int dp[SZ][SZ];

	for(int i=0; i<=52; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
		}
	}

	int N; cin >> N;
	int ans = 0;
	for(int i=1; i<=N/4; i++)
	{
		int val = dp[13][i] * dp[52-i*4][N-i*4] % MOD;
		if(i % 2) ans = (ans + val) % MOD;
		else ans = (MOD + ans - val) % MOD;
	}
	cout << ans;
}