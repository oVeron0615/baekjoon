#include <iostream>
#include <string>
using namespace std;

//dp[i][j] : s1[0]부터 s1[i-1]까지의 문자열과 s2[0]부터 s2[j-1]까지의 문자열의 LCS길이
int dp[2][1001] = {};
string s1, s2;

int main()
{
	cin >> s1 >> s2;

	for (int i{ 1 }; i <= s1.size(); i++)
	{
		for (int j{ 1 }; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
			else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
		}
	}
	cout << dp[s1.size() % 2][s2.size()];
}