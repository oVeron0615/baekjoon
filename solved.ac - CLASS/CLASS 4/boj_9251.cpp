#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXL = 1000;
	int dp[MAXL][MAXL] = {};

	string S1, S2; cin >> S1 >> S2;

	for(int i=0; i<S1.length(); i++)
	{
		for(int j=0; j<S2.length(); j++)
		{
			if(i == 0 && j == 0)
			{
				dp[0][0] = S1[0] == S2[0] ? 1 : 0;
				continue;
			}

			if(S1[i] == S2[j]) 
			{
				if(i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j-1] + 1;
			}
			else 
			{
				if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
				if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[S1.length()-1][S2.length()-1];
}