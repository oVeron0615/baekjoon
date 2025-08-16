#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 15, MAXK = 100;
ll dp[1 << MAXN][MAXK];
int numMod[MAXK][MAXN]; //나머지에 어떤 순열을 붙였을 때의 값
string num[MAXN];
int N, K;

int calModulo(int mod, int idx)
{
	for(char c : num[idx])
	{
		mod = mod * 10 + c - '0';
		mod %= K;
	}
	return mod;
}

ll f(ll n)
{
	ll ret = 1;
	for(ll i=1; i<=n; i++) ret *= i;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=0; i<N; i++) cin >> num[i];
	cin >> K;

	for(int i=0; i<K; i++)
		for(int j=0; j<N; j++)
			numMod[i][j] = calModulo(i, j);

	dp[0][0] = 1;
	for(int i=0; i<(1 << N); i++)
	{
		for(int j=0; j<K; j++)
		{
			for(int k=0; k<N; k++)
			{
				if(i & (1 << k)) continue;
				dp[i | (1 << k)][numMod[j][k]] += dp[i][j];
			}
		}
	}

	ll a = dp[(1 << N) - 1][0], b = f(N);
	ll g = gcd(a, b);
	cout << a / g << "/" << b / g;
}