#include <iostream>
#include <cstring>
using namespace std;

int N, board[100000][3], dp[2][3] = {};

int main()
{
	cin >> N;
	for (int i{ N - 1 }; i >= 0; i--)
	{
		for (int j{ 0 }; j < 3; j++)
		{
			cin >> board[i][j];
		}
	}

	//ÃÖ´ñ°ª
	for (int i{ 0 }; i < N; i++)
	{
		dp[i % 2][0] = board[i][0] + max(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
		dp[i % 2][1] = board[i][1] + max(max(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]), dp[(i + 1) % 2][2]);
		dp[i % 2][2] = board[i][2] + max(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]);
	}
	int mx{ 0 };
	for (int j{ 0 }; j < 3; j++)
	{
		mx = max(mx, dp[(N + 1) % 2][j]);
	}
	cout << mx << " ";
	memset(dp, 0, sizeof(dp));

	//ÃÖ¼Ú°ª
	for (int i{ 0 }; i < N; i++)
	{
		dp[i % 2][0] = board[i][0] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
		dp[i % 2][1] = board[i][1] + min(min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]), dp[(i + 1) % 2][2]);
		dp[i % 2][2] = board[i][2] + min(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]);
	}
	int mn{ 1000000 };
	for (int j{ 0 }; j < 3; j++)
	{
		mn = min(mn, dp[(N + 1) % 2][j]);
	}
	cout << mn;
}