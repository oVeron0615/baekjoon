#include <iostream>
#include <vector>
#include <queue>
#define inf 1e9
using namespace std;

int N, K;
vector<int> dp(100001, inf), trace(100001, inf);

int main()
{
	cin >> N >> K;

	queue<int> qu;
	qu.push(N);
	dp[N] = 0;

	while (!qu.empty())
	{
		int cur = qu.front(); qu.pop();
		if (cur == K) break;

		if (cur - 1 >= 0 && dp[cur - 1] > dp[cur] + 1)
		{
			dp[cur - 1] = dp[cur] + 1;
			trace[cur - 1] = cur;
			qu.push(cur - 1);
		}
		if (cur + 1 <= 100000 && dp[cur + 1] > dp[cur] + 1)
		{
			dp[cur + 1] = dp[cur] + 1;
			trace[cur + 1] = cur;
			qu.push(cur + 1);
		}
		if (cur * 2 <= 100000 && dp[cur * 2] > dp[cur] + 1)
		{
			dp[cur * 2] = dp[cur] + 1;
			trace[cur * 2] = cur;
			qu.push(cur * 2);
		}
	}

	cout << dp[K] << "\n";
	vector<int> t; t.push_back(K);
	while (K != N)
	{
		t.push_back(trace[K]);
		K = trace[K];
	}
	for (int i = t.size() - 1; i >= 0; i--) cout << t[i] << " ";
}