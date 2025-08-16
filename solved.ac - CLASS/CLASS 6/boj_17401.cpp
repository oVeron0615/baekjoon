#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'000'007;
const int MAXT = 101, MAXN = 21;
ll vein[MAXT][MAXN][MAXN];
ll cycle[MAXN][MAXN];
ll res[MAXN][MAXN];

int T, N, D;

void init(ll (&m)[][MAXN])
{
	for(int i=1; i<=N; i++) m[i][i] = 1;
}

void calMatrix(ll (&m1)[][MAXN], ll (&m2)[][MAXN])
{
	ll m[MAXN][MAXN] = {};
	for(int i=1; i<=N; i++) 
		for(int j=1; j<=N; j++) 
			for(int k=1; k<=N; k++)
				m[i][j] += (m1[i][k] * m2[k][j]) % MOD, m[i][j] %= MOD;

	for(int i=1; i<=N; i++) 
		for(int j=1; j<=N; j++)
			m1[i][j] = m[i][j];
}

void solve(ll n)
{
	if(n == 0)
	{
		init(res);
		return;
	}

	solve(n/2);
	calMatrix(res, res);
	if(n % 2) calMatrix(res, cycle);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T >> N >> D;
	for(int t=1; t<=T; t++)
	{
		int M; cin >> M;
		while(M--)
		{
			ll a, b, c; cin >> a >> b >> c;
			vein[t][a][b] = c;
		}
	}

	init(cycle);
	for(int t=1; t<=T; t++) calMatrix(cycle, vein[t]);

	solve(D/T);
	for(int t=1; t<=D%T; t++) calMatrix(res, vein[t]);

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}