#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100001;
	int liq[MAXN];
	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> liq[i];

	int l = 1, r = N;
	int closeVal = INT_MAX;
	pii ans;
	while(l < r)
	{
		int sum = liq[l] + liq[r];
		if(closeVal > abs(sum)) 
		{
			closeVal = abs(sum);
			ans = {liq[l], liq[r]};
		}

		if(sum < 0) l++;
		else r--;
	}
	cout << ans.first << " " << ans.second;
}