#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int V, E, K;
vector<pii> graph[20001];
vector<int> dist(20001, 1e9);
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
	cin >> V >> E >> K;
	for (int i{ 0 }; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	dist[K] = 0;
	pq.push({ dist[K], K });
	while (!pq.empty())
	{
		auto [d, u] = pq.top(); pq.pop();
		for (auto [v, w] : graph[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}

	for (int i{ 1 }; i <= V; i++)
	{
		if (dist[i] == 1e9) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}