#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int L; cin >> L;
	ll r = 31, ri = 1, M = 1234567891;
	ll ans = 0;
	while(L--)
	{
		char c; cin >> c;
		ll ai = c - 'a' + 1;
		ans = (ans + ai * ri % M) % M;
		ri = ri * 31 % M;
	}
	cout << ans;
}