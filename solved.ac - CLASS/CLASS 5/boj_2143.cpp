#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int SZ = 1001;
	ll sumA[SZ] = {}, sumB[SZ] = {};

	int T; cin >> T;
	int n; cin >> n;
	for(int i=1; i<=n; i++)
	{
		ll Ai; cin >> Ai;
		sumA[i] += sumA[i-1] + Ai;
	}
	int m; cin >> m;
	for(int i=1; i<=m; i++)
	{
		ll Bi; cin >> Bi;
		sumB[i] += sumB[i-1] + Bi;
	}

	vector<ll> psumA, psumB;
	for(int i=1; i<=n; i++)
		for(int j=0; j<i; j++)
			psumA.push_back(sumA[i] - sumA[j]);
	for(int i=1; i<=m; i++)
		for(int j=0; j<i; j++)
			psumB.push_back(sumB[i] - sumB[j]);
	
	sort(psumB.begin(), psumB.end());

	ll ans = 0;
	for(int psum : psumA)
	{
		ans += upper_bound(psumB.begin(), psumB.end(), T-psum) 
			- lower_bound(psumB.begin(), psumB.end(), T-psum);
	}
	cout << ans;
}