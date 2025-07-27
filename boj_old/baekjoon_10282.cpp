#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
int n, d, c;
priority_queue<pii, vector<pii>, greater<>> pq;

int main()
{
	int T;
	cin >> T;
	for (int i{ 0 }; i < T; i++)
	{
		vector<pii> com[10001];

		cin >> n >> d >> c;
		for (int j{ 0 }; j < d; j++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			com[b].push_back({ a, s });
		}

		int inf{ 0 }, t{ 0 };
		vector<int> dist(n + 1, INF);
		vector<bool> check(n + 1, false);

		dist[c] = 0;
		pq.push({ dist[c], c });
		check[c] = true;
		while (!pq.empty())
		{
			auto [s, b] = pq.top(); pq.pop();
			if (dist[b] < s) continue;
			for (auto [a, d] : com[b])
			{
				if (dist[a] > dist[b] + d)
				{
					dist[a] = dist[b] + d;
					pq.push({ dist[a], a });
					check[a] = true;
				}
			}
		}

		for (int i{ 1 }; i <= n; i++)
		{
			if (check[i])
			{
				inf++;
				t = max(t, dist[i]);
			}
		}
		cout << inf << " " << t << "\n";
	}
}