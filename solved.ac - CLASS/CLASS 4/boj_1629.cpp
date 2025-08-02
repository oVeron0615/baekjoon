#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll solve(ll A, ll B, ll C)
{
	if(B == 1) return A % C;

	ll val = solve(A, B / 2, C);
	ll ret = val * val % C;
	return (B % 2) ? (ret * A) % C : ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll A, B, C; cin >> A >> B >> C;
	cout << solve(A, B, C);
}