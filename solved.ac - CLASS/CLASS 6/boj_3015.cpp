#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll ans = 0;
	stack<pll> st;

	int N; cin >> N;
	while(N--)
	{
		ll h; cin >> h;

		while(!st.empty() && st.top().first < h)
		{
			ans += st.top().second;
			st.pop();
		}

		if(st.empty()) st.push({h, 1});
		else if(st.top().first == h)
		{
			if(st.size() == 1) ans += st.top().second;
			else ans += st.top().second + 1;
			st.top().second++;
		}
		else
		{
			ans++;
			st.push({h, 1});
		}
	}
	cout << ans;
}