#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll K, N; cin >> K >> N;
	vector<ll> lans(K);
	for(ll& lan : lans) cin >> lan;

	ll l = 1, r = INT_MAX;
	ll ans;
	while(l <= r)
	{
		ll m = (l + r) / 2;
		ll cnt = 0;
		for(ll lan : lans) cnt += lan / m;

		if(cnt >= N) ans = m, l = m + 1;
		else r = m - 1;
	}
	cout << ans;
}