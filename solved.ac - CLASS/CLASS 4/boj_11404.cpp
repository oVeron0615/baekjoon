#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 101, INF = 1e9;
int n, m;
int dp[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(&dp[0][0], &dp[0][0] + MAXN * MAXN, INF);

	cin >> n >> m;
	while(m--)
	{
		int a, b, c; cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}
	for(int i=1; i<=n; i++) dp[i][i] = 0;

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(dp[i][j] == INF) cout << 0 << " ";
			else cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}