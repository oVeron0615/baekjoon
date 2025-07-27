#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main()
{
	string s1, s2, s; cin >> s1 >> s2;

	for (int i{ 1 }; i <= s1.size(); i++)
	{
		for (int j{ 1 }; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int x = s1.size(), y = s2.size();
	while (dp[x][y] != 0)
	{
		cout << x << " " << y << endl;
		if (dp[x - 1][y] == dp[x][y]) x--;
		else if(dp[x][y - 1] == dp[x][y]) y--;
		else
		{
			s += s1[x - 1];
			x--; y--;
		}
	}

	if (dp[s1.size()][s2.size()] == 0) cout << 0;
	else
	{
		cout << dp[s1.size()][s2.size()] << "\n";
		for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
	}
}