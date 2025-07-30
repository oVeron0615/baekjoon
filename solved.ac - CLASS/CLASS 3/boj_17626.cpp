#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> dp(50001, 1e9);
	dp[0] = 0;
	for(int i=1; i<=n; i++)
	{
		for(int sq=1; sq*sq<=i; sq++)
		{
			dp[i] = min(dp[i], dp[i-sq*sq] + 1);
		}
	}
	cout << dp[n];
}