#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MOD = 10'007, SZ = 1000;
	int dp[SZ][SZ];
	string S; cin >> S;

	for(int len=0; len<S.size(); len++)
	{
		for(int i=0; i+len<S.size(); i++)
		{
			int j = i + len;
			if(len == 0) dp[i][j] = 1;
			else if(len == 1)
			{
				dp[i][j] = 2;
				if(S[i] == S[j]) dp[i][j] += 1;
			} 
			else
			{
				dp[i][j] = (MOD + dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % MOD;
				if(S[i] == S[j]) dp[i][j] += dp[i+1][j-1] + 1, dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[0][S.size()-1];
}