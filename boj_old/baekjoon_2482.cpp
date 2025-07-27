#include <iostream>
#include <cstring>
#define mod 1000000003
using namespace std;

bool check{ true };
int N, K;
int dp[1000][1000]; //dp[x][y] = x���� N - 1���� y���� ���� �� ����� ��

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
	if (check) //�� ó�� ���� ���� ���
	{
		if (y == 0) return 1;
		else if (x >= N - 1) return 0;
	}
	else //�� ó�� ���� ������ ���� ���
	{
		if (y == 0) return 1;
		else if (x >= N) return 0;
	}

	if (dp[x][y] != -1) return dp[x][y];

	//�ش� ���� �������� ���� dp[x + 2][y - 1], ������ �ʾ��� ���� dp[x + 1][y]
	return dp[x][y] = (f(x + 2, y - 1) + f(x + 1, y)) % mod;
}