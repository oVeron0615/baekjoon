#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int main()
{
	vector<array<int, 2>> wire;
	int n, dp[100]; //dp[i] = i번째까지 남아있는 최대 전깃줄의 수

	cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		array<int, 2> w;
		cin >> w[0] >> w[1];
		wire.push_back(w);
	}
	sort(wire.begin(), wire.end()); //wire 오름차순 정렬

	int k{ 0 };
	for (int i{ 0 }; i < n; i++)
	{
		int mx{ 0 };
		for (int j{ 0 }; j < i; j++)
		{
			//전깃줄이 안 겹치면 LIS를 돌려본다
			if (wire[i][0] > wire[j][0] && wire[i][1] > wire[j][1])
			{
				mx = max(mx, dp[j]);
			}
		}
		dp[i] = mx + 1;
		k = max(k, dp[i]);
	}
	cout << n - k;
}