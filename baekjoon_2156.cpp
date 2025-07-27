#include <iostream>
#include <cstring>
using namespace std;

int n, wine[10010] = {};
int dp[10010]; //dp[i] = i��° �����ֱ��� ���� �� �ִ� ������ ���� �ִ�;

int f(int);

int main()
{
	cin >> n;
	for (int i{ 0 }; i < n; i++) cin >> wine[i];
	memset(dp, -1, sizeof(dp));

	cout << max(f(0), f(1)); //ù ��° ������ ������ ��, �� ������ ���� ��
}

int f(int x) //�� ���� ��츦 ���� �ִ��� dp�� ����
{
	if (x >= n) return 0;
	if (dp[x] != -1) return dp[x];

	int temp1 = f(x + 2);
	int temp2 = wine[x + 1] + f(x + 3);
	int temp3 = wine[x + 1] + f(x + 4);

	return dp[x] = max(max(temp1, temp2), temp3) + wine[x];
}