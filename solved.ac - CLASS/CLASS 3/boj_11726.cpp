#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int mod = 10007;
	int n; cin >> n;
	vector<ll> dp(1001);
	dp[1] = 1, dp[2] = 2;
	for(int i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2]) % mod;
	cout << dp[n];
}