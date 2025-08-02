#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int C = 100000;
	const int R = 2;
	int sticker[R][C], dp[R][C];

	int T; cin >> T;
	while(T--)
	{
		int n; cin >> n;
		for(int i=0; i<R; i++)
			for(int j=0; j<n; j++)
				cin >> sticker[i][j];
		
		fill(&dp[0][0], &dp[0][0] + R * C, 0);
		for(int j=0; j<n; j++)
		{
			for(int i=0; i<R; i++)
			{
				if(j > 0) dp[i][j] = max(dp[i][j], dp[1-i][j-1]);
				if(j > 1) dp[i][j] = max(dp[i][j], dp[1-i][j-2]);
				dp[i][j] += sticker[i][j];
			}
		}

		int ans = 0;
		for(int i=0; i<R; i++)
			for(int j=0; j<n; j++)
				ans = max(ans, dp[i][j]);
		cout << ans << "\n";
	}
}