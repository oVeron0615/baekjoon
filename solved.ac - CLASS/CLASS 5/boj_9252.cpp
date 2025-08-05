#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int SZ = 1001;
	int dp[SZ][SZ] = {};
	string s1, s2; cin >> s1 >> s2;

	for(int i=1; i<=s1.size(); i++)
	{
		for(int j=1; j<=s2.size(); j++)
		{
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[s1.size()][s2.size()] << "\n";

	vector<char> ans;
	int x = s1.size(), y = s2.size();
	while(x > 0 && y > 0)
	{
		if(s1[x-1] == s2[y-1]) 
		{
			ans.push_back(s1[x-1]);
			x--, y--;
		}
		else if(dp[x-1][y] > dp[x][y-1]) x--;
		else y--;
	}
	reverse(ans.begin(), ans.end());
	for(char c : ans) cout << c;
}