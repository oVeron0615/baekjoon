#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 101, MAXM = 10;
const ll MOD = 1'000'000'000;
ll dp[MAXN][MAXM][1 << MAXM];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<MAXM; i++) dp[1][i][1 << i] = 1;

	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<MAXM; j++)
		{
			for(int k=0; k<(1 << MAXM); k++)
			{
				if(j-1 >= 0) dp[i][j][k | (1 << j)] += dp[i-1][j-1][k], dp[i][j][k | (1 << j)] %= MOD;
				if(j+1 < MAXM) dp[i][j][k | (1 << j)] += dp[i-1][j+1][k], dp[i][j][k | (1 << j)] %= MOD;
			}
		}
	}

	ll ans = 0;
	for(int i=0; i<MAXM; i++)
		ans += dp[N][i][(1 << MAXM) - 1], ans %= MOD;
	cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 101, MAXM = 10;
const ll MOD = 1'000'000'000;
ll dp[MAXN][MAXM][1 << MAXM];
int N;

ll solve(int i, int j, int k)
{
	ll& ret = dp[i][j][k];
	if(ret != -1) return ret;
	if(i == N)
	{
		if(k == (1 << MAXM) - 1) return ret = 1;
		else return ret = 0;
	}

	ret = 0;
	if(j-1 >= 0) ret += solve(i+1, j-1, k | (1 << (j-1))), ret %= MOD;
	if(j+1 <= 9) ret += solve(i+1, j+1, k | (1 << (j+1))), ret %= MOD;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for(int i=1; i<MAXM; i++)
		ans += solve(1, i, (1 << i)), ans %= MOD;
	cout << ans;
}
*/