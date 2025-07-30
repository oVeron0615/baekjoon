#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--)
	{
		int n; cin >> n;
		map<string, int> clothes_cnt;

		while(n--)
		{
			string name, clothes; cin >> name >> clothes;
			clothes_cnt[clothes]++;
		}

		int ans = 1;
		for(auto i = clothes_cnt.begin(); i != clothes_cnt.end(); i++)
			ans *= (i->second + 1);
		ans--;
		cout << ans << "\n";
	}
}