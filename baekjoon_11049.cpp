#include <iostream>
using namespace std;

//dp[i][j] = i번째부터 j번째까지의 행렬을 연산할때 필요한 최소 연산 수
int N;
int matrix[500][2], dp[500][500] = {};

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> matrix[i][0] >> matrix[i][1];
	}

	for (int a{ 1 }; a < N; a++)
	{
		for (int b{ 0 }; b < N - a; b++)
		{
			if (a == 1)
			{
				dp[b][a + b] = matrix[b][0] * matrix[b][1] * matrix[a + b][1];
			}
			else
			{
				int mn = 2147483647, temp;
				for (int c{ 0 }; c < a; c++)
				{
					if (c == 0)
					{
						temp = dp[b + 1][a + b] +
							matrix[b][0] * matrix[a + b][1] * matrix[b][1];
					}
					else if (c == a - 1)
					{
						temp = dp[b][a + b - 1] +
							matrix[b][0] * matrix[a + b][1] * matrix[a + b][0];
					}
					else
					{
						temp = dp[b][b + c] + dp[b + c + 1][a + b]
							+ matrix[b][0] * matrix[a + b][1] * matrix[b + c][1];
					}

					if (mn > temp) mn = temp;
				}
				dp[b][a + b] = mn;
			}
		}
	}
	cout << dp[0][N - 1];
}