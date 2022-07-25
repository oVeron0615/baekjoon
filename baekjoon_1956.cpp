#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	typedef pair<int, int> pii;
	vector<pii> graph[401];

	int V, E; cin >> V >> E;
	for (int i{ 0 }; i < E; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	long long mn = 1e10;
	for (int i{ 1 }; i < V; i++)
	{
		vector<long long> dist(401, 1e10);
		priority_queue<pii, vector<pii>, greater<pii>> pq;

		dist[i] = 0;
		pq.push({ dist[i], i});
		while (!pq.empty())
		{
			auto [d, a] = pq.top(); pq.pop();

			if (d > dist[a]) continue;
			for (auto [b, c] : graph[a])
			{
				if (dist[b] > dist[a] + c)
				{
					dist[b] = dist[a] + c;
					if(b != i) pq.push({ dist[b], b });
				}
			}

			if (a == i) dist[a] = 1e10;
		}
		mn = min(mn, dist[i]);
	}
	if (mn == 1e10) cout << -1;
	else cout << mn;
}