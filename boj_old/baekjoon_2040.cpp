#include <iostream>
#define inf 1e9
using namespace std;

int nsum[3001];
int arr[3001][3001];
int dp[3001][3001];
int mn[3001];

int main()
{
	int n; cin >> n;
	for (int t{ 1 }; t <= 3; t++)
	{
		for (int i{ 1 }; i <= n; i++)
		{
			int a; cin >> a;
			nsum[i] = nsum[i - 1] + a;
		}

		for (int i{ 1 }; i <= n; i++)
		{
			for (int j{ 1 }; j <= n - i + 1; j++)
			{
				arr[i][j] = nsum[n - i + 1] - nsum[j - 1];
			}
		}

		for (int i{ 1 }; i <= n; i++) mn[i] = inf;

		for (int j{ 1 }; j <= n; j++)
		{
			for (int i{ 1 }; i <= n - j + 1; i++)
			{
				if (j == 1) dp[i][j] = arr[i][j];
				else dp[i][j] = arr[i][j] - mn[n - j + 2];
				mn[i] = min(mn[i], dp[i][j]);
			}
		}

		if (mn[1] < 0) cout << 'A' << "\n";
		else if (mn[1] > 0) cout << 'B' << "\n";
		else cout << 'D' << "\n";
	}
}