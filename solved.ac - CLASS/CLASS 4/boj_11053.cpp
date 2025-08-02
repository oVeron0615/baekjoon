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
	int A[SZ];

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	int ans = 0;
	int dp[SZ] = {};
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<i; j++)
		{
			if(A[i] > A[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += 1;
		ans = max(ans, dp[i]);
	}
	cout << ans;
}