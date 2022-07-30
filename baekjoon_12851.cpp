#include <iostream>
#include <vector>
#include <stack>
#define inf 1e9
using namespace std;

int main()
{
	int N, K; cin >> N >> K;

	vector<int> dist(100001, inf);
	typedef pair<int, int> pii;
	stack<pii> qu;

	int dis = inf, cnt{ 1 };
	qu.push({ N, 0 });
	while (!qu.empty())
	{
		auto [cur, len] = qu.top(); qu.pop();
		if (len > dis) break;

		if (cur == K)
		{
			if (dist[K] > len)
			{
				dist[K] = len;
				dis = len; cnt = 1;
			}
			else if (dist[K] == len) cnt++;
			continue;
		}

		if (dist[cur] < len) continue;
		else dist[cur] = len;

		if (cur - 1 >= 0) qu.push({ cur - 1, len + 1 });
		if (cur + 1 <= 100000) qu.push({ cur + 1, len + 1 });
		if (cur * 2 <= 100000) qu.push({ cur * 2, len + 1 });
	}
	cout << dist[K] << "\n" << cnt;
}