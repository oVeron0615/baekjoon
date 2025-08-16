#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n; cin >> n;
	ll ans = n;
	for(ll i=2; i*i<=n; i++) //소인수분해
	{
		if(n % i == 0)
		{
			while(n % i == 0) n /= i;
			ans -= ans / i; //앞에서부터 n(1-1/pk)를 차례대로 계산
		}
	}
	if(n > 1) ans -= ans / n;
	cout << ans;
}