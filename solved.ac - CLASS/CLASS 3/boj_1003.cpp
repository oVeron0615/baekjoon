#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//bottom - up DP
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	vector<pll> dp(41);
	dp[0] = {1, 0}, dp[1] = {0, 1};
	for(int i=2; i<=40; i++)
		dp[i] = {dp[i-1].F + dp[i-2].F, dp[i-1].S + dp[i-2].S};

	while(T--)
	{
		int N; cin >> N;
		cout << dp[N].F << " " << dp[N].S << "\n";
	}
}

//top - down DP
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void fibo(vector<pll>& DP, int n)
{
	if(DP[n] != pll(-1, -1)) return;
	if(n == 0) 
	{
		DP[n] = {1, 0};
		return;
	}
	if(n == 1) 
	{
		DP[n] = {0, 1};
		return;
	}

	fibo(DP, n-1);
	fibo(DP, n-2);
	DP[n] = {DP[n-1].first + DP[n-2].first, DP[n-1].second + DP[n-2].second};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--)
	{
		int N; cin >> N;
		vector<pll> DP(N+1, {-1, -1});
		fibo(DP, N);
		cout << DP[N].first << " " << DP[N].second << "\n";
	}
}
*/