#include <iostream>
#include <cstring>
#define mod 1000000003
using namespace std;

bool check{ true };
int N, K;
int dp[1000][1000]; //dp[x][y] = x부터 N - 1까지 y개의 색을 고를 경우의 수

int f(int, int);

int main()
{
	cin >> N >> K;

	int ans{ 0 };
	memset(dp, -1, sizeof(dp));
	ans += f(2, K - 1);

	check = false;
	memset(dp, -1, sizeof(dp));
	ans += f(1, K);

	cout << ans % mod;
}

int f(int x, int y)
{
	if (check) //맨 처음 색을 택할 경우
	{
		if (y == 0) return 1;
		else if (x >= N - 1) return 0;
	}
	else //맨 처음 색을 택하지 않을 경우
	{
		if (y == 0) return 1;
		else if (x >= N) return 0;
	}

	if (dp[x][y] != -1) return dp[x][y];

	//해당 색을 선택했을 때는 dp[x + 2][y - 1], 택하지 않았을 때는 dp[x + 1][y]
	return dp[x][y] = (f(x + 2, y - 1) + f(x + 1, y)) % mod;
}