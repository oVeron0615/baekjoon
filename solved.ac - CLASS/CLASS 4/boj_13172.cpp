#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'000'007;

ll solve(int N, int X)
{
	if(X == 0) return 1;

	ll val = solve(N, X/2);
	val *= val, val %= MOD;
	if(X % 2) val *= N, val %= MOD;
	return val;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int M; cin >> M;
	ll ans = 0;
	while(M--)
	{
		int N, S; cin >> N >> S;
		ans += S * solve(N, MOD-2) % MOD, ans %= MOD;
	}	
	cout << ans;
}