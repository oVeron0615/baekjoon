#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 17;
	int dp[MAXN][MAXN][3] = {};
	int board[MAXN][MAXN];

	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin >> board[i][j];
		}
	}

	dp[1][2][0] = 1;
	for(int i=1; i<=N; i++)
	{
		for(int j=3; j<=N; j++)
		{
			if(board[i][j]) continue;
			dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
			dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
			if(!board[i-1][j] && !board[i][j-1])
				dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
		}
	}

	int ans = 0;
	for(int i=0; i<3; i++) ans += dp[N][N][i];
	cout << ans;
}