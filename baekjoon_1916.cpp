#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	typedef pair<int, int> pii;
	vector<long long> cost(1001, 1e18);
	vector<pii> graph[1001];
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	int N, M; cin >> N >> M;
	for (int i{ 0 }; i < M; i++)
	{
		int u, v, c; cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}

	int start, end; cin >> start >> end;
	cost[start] = 0;
	pq.push({ cost[start], start });
	while (!pq.empty())
	{
		auto [c, u] = pq.top(); pq.pop();
		if (c > cost[u]) continue;

		for (auto [v, c] : graph[u])
		{
			if (cost[v] > cost[u] + c)
			{
				cost[v] = cost[u] + c;
				pq.push({ cost[v], v });
			}
		}
	}

	cout << cost[end];
}