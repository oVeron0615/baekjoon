#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
vector<int> vis(100001, 1e9);
queue<int> qu;

int main()
{
	cin >> N >> K;
	
	qu.push(N);
	vis[N] = 0;
	while (!qu.empty())
	{
		int cur = qu.front(); qu.pop();
		if (cur == K) continue;

		if (cur + 1 <= 100000 && vis[cur + 1] > vis[cur] + 1)
		{
			vis[cur + 1] = vis[cur] + 1;
			qu.push(cur + 1);
		}
		if (cur - 1 >= 0 && vis[cur - 1] > vis[cur] + 1)
		{
			vis[cur - 1] = vis[cur] + 1;
			qu.push(cur - 1);
		}
		if (cur * 2 <= 100000 && vis[cur * 2] > vis[cur])
		{
			vis[cur * 2] = vis[cur];
			qu.push(cur * 2);
		}
	}
	cout << vis[K];
}