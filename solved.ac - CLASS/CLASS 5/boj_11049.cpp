#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 501, INF = 1e9;
pii M[MAXN];
int dp[MAXN][MAXN] = {};
int N;

int matCal(int a, int b, int c)
{
	return M[a].first * M[b].second * M[c].second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int r, c; cin >> r >> c;
		M[i] = {r, c};
	}

	fill(&dp[0][0], &dp[0][0] + MAXN * MAXN, INF);
	for(int i=1; i<=N; i++) dp[i][i] = 0;
	
	for(int j=1; j<N; j++)
		for(int i=1; i+j<=N; i++)
			for(int k=i; k<i+j; k++)
				dp[i][i+j] = min(dp[i][i+j], dp[i][k] + dp[k+1][i+j] + matCal(i, k, i+j));

	cout << dp[1][N];
}