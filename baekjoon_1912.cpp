#include <iostream>
using namespace std;

long long dp[100000]; //dp[i] = i까지 연속합의 최댓값
int arr[100000];

int main()
{
	int n;
	long long mx;

	cin >> n; 
	for (int i{ 0 }; i < n; i++)
	{
		cin >> arr[i];
		if (i == 0) //맨 처음
		{
			dp[i] = arr[i];
			mx = arr[i];
		}
		else
		{
			//i-1까지 연속합의 최댓값과, 현재의 값을 포함한 연속합의 최댓값을 비교
			mx = max(mx, long long(0)) + arr[i];
			dp[i] = max(dp[i - 1], mx);
		}
	}
	cout << dp[n - 1];
}