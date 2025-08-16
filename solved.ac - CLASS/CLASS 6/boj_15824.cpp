#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 300001;
	const ll MOD = 1'000'000'007;
	ll menu[MAXN], pow2[MAXN];

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> menu[i];
	sort(menu + 1, menu + N + 1);

	pow2[0] = 1;
	for(int i=1; i<=N; i++) pow2[i] = pow2[i-1] * 2 % MOD;

	ll ans = 0;
	for(int i=1; i<=N; i++)
	{
		ans += menu[i] * ((pow2[i-1] - pow2[N-i] + MOD) % MOD) % MOD;
		ans %= MOD;
	}
	cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'000'007;

ll square2(ll n)
{
	if(n == 0) return 1;

	ll ret = square2(n/2);
	ret *= ret, ret %= MOD;

	if(n % 2) return ret *= 2, ret %= MOD;
	else return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 300001;
	ll menu[MAXN], sum[MAXN] = {};

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> menu[i];
	sort(menu + 1, menu + 1 + N);

	for(int i=1; i<=N; i++) sum[i] = (sum[i-1] + menu[i]) % MOD;

	ll ans = 0;
	for(int i=0; i<N-1; i++)
	{
		ans += square2(i) * ((MOD * 2 + sum[N] - sum[i+1] - sum[N-(i+1)]) % MOD) % MOD;
		ans %= MOD;
	}
	cout << ans;
}
*/