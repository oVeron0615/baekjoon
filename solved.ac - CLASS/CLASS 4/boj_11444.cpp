#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'000'007;
ll f[2][2] = {{1, 1}, {1, 0}};
ll res[2][2] = {};

void calMatrix(ll (&m1)[][2], ll (&m2)[][2])
{
	ll m[2][2] = {};
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
	m[i][j] += (m1[i][k] * m2[k][j]) % MOD, m[i][j] %= MOD;

	for(int i=0; i<2; i++) for(int j=0; j<2; j++)
	m1[i][j] = m[i][j];
}

void solve(ll n)
{
	if(n == 0)
	{
		for(int i=0; i<2; i++) res[i][i] = 1;
		return;
	}

	solve(n/2);
	calMatrix(res, res);
	if(n % 2) calMatrix(res, f);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n; cin >> n;
	solve(n);
	cout << res[1][0];
}