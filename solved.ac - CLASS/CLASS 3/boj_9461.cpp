#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll dp[101];
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for(int i=6; i<=100; i++) dp[i] = dp[i-1] + dp[i-5];
	
	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		cout << dp[N] << "\n";
	}
}