#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const ll MAXN = 5001, INF = 1e18;
	ll liq[MAXN];

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> liq[i];
	sort(liq + 1, liq + N + 1);

	ll closeVal = INF;
	ll ans1, ans2, ans3;
	for(int i=1; i<=N; i++)
	{
		int l = i+1, r = N;
		while(l < r)
		{
			ll sum = liq[i] + liq[l] + liq[r];
			if(closeVal > abs(sum)) closeVal = abs(sum), ans1 = liq[i], ans2 = liq[l], ans3 = liq[r];
			if(sum < 0) l++;
			else r--;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3;
}