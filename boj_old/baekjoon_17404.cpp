#include <iostream>
#include <cstring>
using namespace std;

int N, k;
int house[1000][3], dp[1000][3];

int f(int, int);

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < 3; j++)
		{
			cin >> house[i][j];
		}
	}

	int ans = 1e9;
	for (int i{ 0 }; i < 3; i++)
	{
		memset(dp, -1, sizeof(dp));
		k = i;
		ans = min(ans, f(0, i));
	}
	cout << ans;
}

int f(int index, int color)
{
	if (index == N - 1)
	{
		if (color == k) return 1e9;
		else return dp[index][color] = house[index][color];
	}
	if (dp[index][color] != -1) return dp[index][color];

	if (color == 0) return dp[index][color] = min(f(index + 1, 1), f(index + 1, 2)) + house[index][color];
	else if (color == 1) return dp[index][color] = min(f(index + 1, 0), f(index + 1, 2)) + house[index][color];
	else if (color == 2) return dp[index][color] = min(f(index + 1, 0), f(index + 1, 1)) + house[index][color];
}