#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10'001, INF = 1e9;
int N, W;
int board[2][MAXN];
int dp[4][MAXN][3];

void solve()
{
	cin >> N >> W;
	for(int i=1; i<=N; i++) cin >> board[0][i];
	for(int i=1; i<=N; i++) cin >> board[1][i];

	fill(&dp[0][0][0], &dp[0][0][0] + 4 * 3 * MAXN, INF);
	dp[0][0][0] = 0;
	dp[0][1][1] = dp[0][1][2] = 1;
	dp[0][1][0] = (board[0][1] + board[1][1] <= W) ? 1 : 2;
	if(board[0][1] + board[0][N] <= W) dp[1][1][1] = 1, dp[1][1][0] = 2;
	if(board[1][1] + board[1][N] <= W) dp[2][1][2] = 1, dp[2][1][0] = 2;
	if(board[0][1] + board[0][N] <= W && board[1][1] + board[1][N] <= W)
		dp[3][1][0] = 2;

	for(int i=0; i<4; i++)
	{
		for(int j=2; j<=N; j++)
		{
			if(board[0][j] + board[0][j-1] <= W) dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][2] + 1);
			dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + 1);

			if(board[1][j] + board[1][j-1] <= W) dp[i][j][2] = min(dp[i][j][2], dp[i][j-1][1] + 1);
			dp[i][j][2] = min(dp[i][j][2], dp[i][j-1][0] + 1);

			dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1);
			dp[i][j][0] = min(dp[i][j][0], dp[i][j][2] + 1);
			if(board[0][j] + board[1][j] <= W) dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][0] + 1);
			if(board[0][j] + board[0][j-1] <= W && board[1][j] + board[1][j-1] <= W) 
				dp[i][j][0] = min(dp[i][j][0], dp[i][j-2][0] + 2);
		}
	}
	
	cout << min(min(dp[0][N][0], dp[1][N][2]), min(dp[2][N][1], dp[3][N-1][0])) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}