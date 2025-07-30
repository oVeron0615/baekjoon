#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> trees(N);
	for(int& tree : trees) cin >> tree;

	int l = 0, r = 2'000'000'000;
	int ans;
	while(l <= r)
	{
		int m = (l + r) / 2;

		ll sum = 0;
		for(int tree : trees) 
			sum += tree > m ? tree - m : 0;
		
		if(sum >= M) ans = m, l = m + 1;
		else r = m - 1;
	}
	cout << ans;
}