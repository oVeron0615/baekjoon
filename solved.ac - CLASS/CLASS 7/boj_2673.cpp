#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 100;
int N; 
int isLine[SZ][SZ];
int dp[SZ][SZ];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	while(N--)
	{
		int x, y; cin >> x >> y;
		x--, y--;
		isLine[x][y] = isLine[y][x] = 1;
	}

	int ans = 0;
	for(int len=1; len<=SZ; len++)
	{
		for(int i=0; i<SZ; i++)
		{
			int j = (i + len) % SZ;
			int k = i;
			while(k < j)
			{
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[(k+1)%SZ][j] + isLine[i][j]);
				k = (k + 1) % SZ;
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
} 