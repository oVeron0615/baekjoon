#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2500, INF = 1e9;
bool isPalin[SZ][SZ];
int dp[SZ];
string S;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> S;
	for(int len=0; len<S.length(); len++)
	{
		for(int i=0; i+len<S.length(); i++)
		{
			int j = i + len;
			isPalin[i][j] = (S[i] == S[j] && (j-i < 2 || isPalin[i+1][j-1]));
		}
	}

	fill(&dp[0], &dp[0] + SZ, INF);
	for(int j=0; j<S.length(); j++)
	{
		for(int i=0; i<=j; i++)
		{
			if(isPalin[i][j])
			{
				if(i == 0) dp[j] = 1;
				else dp[j] = min(dp[j], dp[i-1] + 1);
			}
			else dp[j] = min(dp[j], dp[j-1] + 1);
		}
	}
	cout << dp[S.length()-1];
}