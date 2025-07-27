#include <iostream>
using namespace std;

int file[500], merge[500][500], dp[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T, K;
	cin >> T;
	for (int i{ 0 }; i < T; i++)
	{
		cin >> K;
		for (int j{ 0 }; j < K; j++) cin >> file[j];

		for (int a{ 0 }; a < K; a++)
		{
			for (int b{ 0 }; b < K - a; b++)
			{
				if (a == 0) merge[b][a + b] = file[b];
				else
				{
					int mn = 1e9;
					for (int c{ 0 }; c < a; c++)
					{
						mn = min(mn, merge[b][b + c] + merge[b + c + 1][a + b]);
					}
					merge[b][a + b] = mn;
				}
			}
		}
		
		for (int a{ 0 }; a < K; a++)
		{
			for (int b{ 0 }; b < K - a; b++)
			{
				if (a == 0) dp[b][a + b] = merge[b][a + b];
				else
				{
					int mn = 1e9;
					for (int c{ 0 }; c < a; c++)
					{
						int sum{ 0 };
						if (c != 0) sum += dp[b][b + c];
						if (c != a - 1) sum += dp[b + c + 1][a + b];
						mn = min(mn, sum);
					}
					dp[b][a + b] = mn + merge[b][a + b];
				}
			}
		}
		cout << dp[0][K - 1] << endl;
	}
}