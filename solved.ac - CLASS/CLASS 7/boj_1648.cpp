#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 14;
int N, M;
int dp[SZ * SZ][1 << SZ];
const int MOD = 9901;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	dp[0][0] = 1;
	for(int i=0; i<N*M; i++)
	{
		for(int j=0; j<(1 << M); j++)
		{
			dp[i][j] %= MOD;
			if(j & (1 << 0) && i+1 < N*M) dp[i+1][j >> 1] += dp[i][j];
			else
			{
				if(i / M < N-1) dp[i+1][(j >> 1) | (1 << (M-1))] += dp[i][j];
				if(i % M < M-1 && !(j & (1 << 1))) dp[i+1][(j >> 1) | (1 << 0)] += dp[i][j];
			}
		}
	}
	cout << dp[N*M-1][1];
} 