#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'000'007;
const int SZ = 8;
ll f[SZ][SZ] = 
{
	{0, 1, 0, 1, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{0, 1, 0, 1, 1, 1, 0, 0},
	{1, 1, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};
ll res[SZ][SZ];

void calMatrix(ll (&m1)[][SZ], ll (&m2)[][SZ])
{
	ll m[SZ][SZ] = {};
	for(int i=0; i<SZ; i++)
		for(int j=0; j<SZ; j++)
			for(int k=0; k<SZ; k++)
				m[i][j] += (m1[i][k] * m2[k][j]) % MOD, m[i][j] %= MOD;
	
	for(int i=0; i<SZ; i++)
		for(int j=0; j<SZ; j++)
			m1[i][j] = m[i][j];
}

void solve(int D)
{
	if(D == 0)
	{
		for(int i=0; i<SZ; i++) res[i][i] = 1;
		return;
	}

	solve(D/2);
	calMatrix(res, res);
	if(D % 2) calMatrix(res, f);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int D; cin >> D;
	solve(D);

	cout << res[0][0];
}