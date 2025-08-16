#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4'000'001;
const ll MOD = 1'000'000'007;
ll f[MAXN];

ll sq(ll n, ll val)
{
	if(n == 0) return 1;

	ll res = sq(n/2, val);
	res *= res, res %= MOD;
	if(n % 2) res *= val, res %= MOD;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	f[0] = 1;
	for(int i=1; i<MAXN; i++) f[i] = (f[i-1] * i) % MOD;

	int M; cin >> M;
	while(M--)
	{
		int N, K; cin >> N >> K;
		cout << f[N] * sq(MOD-2, (f[K] * f[N-K]) % MOD) % MOD << "\n";
	}
}