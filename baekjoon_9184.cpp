#include <iostream>
#include <cstring>
using namespace std;

int dp[102][102][102];

int w(int, int, int);

int main()
{
	int a, b, c;
	memset(dp, -1, sizeof(dp));

	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		cout << "w(" << a << ", " << b << ", " << c << ") = "
			<< w(a + 50, b + 50, c + 50) << endl;
	}
}

int w(int a, int b, int c)
{
	if (dp[a][b][c] != -1) return dp[a][b][c];

	if (a <= 50 || b <= 50 || c <= 50) return dp[a][b][c] = 1;
	if (a > 70 || b > 70 || c > 70) return dp[a][b][c] = w(70, 70, 70);
	if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}