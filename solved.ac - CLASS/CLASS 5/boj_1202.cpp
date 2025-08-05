#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

auto cmp = [](pll p1, pll p2)
{
	if(p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<pll> jewel;

	int N, K; cin >> N >> K;
	for(int i=1; i<=N; i++)
	{
		ll Mi, Vi; cin >> Mi >> Vi;
		jewel.push_back({Vi, Mi});
	}
	sort(jewel.begin(), jewel.end(), cmp);

	multiset<ll> bag;
	for(int i=1; i<=K; i++)
	{
		ll Ci; cin >> Ci;
		bag.insert(Ci);
	}

	ll ans = 0;
	for(auto [V, M] : jewel)
	{
		auto iter = bag.lower_bound(M);
		if(iter != bag.end())
		{
			ans += V;
			bag.erase(iter);
		}
	}
	cout << ans;
}