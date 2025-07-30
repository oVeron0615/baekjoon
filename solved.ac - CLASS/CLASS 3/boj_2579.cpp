#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> score(N+1);
	for(int i=1; i<=N; i++) cin >> score[i];

	vector<vector<int>> dp(N+1, vector<int>(2, 0));
	dp[1][0] = dp[1][1] = score[1];
	for(int i=2; i<=N; i++) 
	{
		for(int j=0; j<2; j++)
		{
			if(j == 1) dp[i][j] = dp[i-1][0];
			dp[i][j] = max(dp[i][j], 
				max(dp[i-2][0], dp[i-2][1])) + score[i];
		}
	}
	cout << max(dp[N][0], dp[N][1]);
}