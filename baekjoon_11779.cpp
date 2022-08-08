#include <iostream>
#include <vector>
#include <queue>
#define inf 1e9
using namespace std;

int main()
{	
	typedef pair<int, int> pii;
	vector<pii> graph[1001];
	vector<int> cost(1001, inf);
	vector<int> city[1001];

	int n, m; cin >> n >> m;
	for (int i{ 0 }; i < m; i++)
	{
		int u, v, d; cin >> u >> v >> d;
		graph[u].push_back({ v, d });
	}
	int s, e; cin >> s >> e;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ s, 0 });
	city[s].push_back(s);
	cost[s] = 0; 
	while (!pq.empty())
	{
		auto [u, d] = pq.top(); pq.pop();
		if (cost[u] < d) continue;

		for (auto [v, d] : graph[u])
		{
			if (cost[v] > cost[u] + d)
			{
				cost[v] = cost[u] + d;
				pq.push({ v, cost[v] });

				city[v].clear();
				for (int i{ 0 }; i < city[u].size(); i++)
				{
					city[v].push_back(city[u][i]);
				}
				city[v].push_back(v);
			}
		}
	}

	cout << cost[e] << "\n" << city[e].size() << "\n";
	for (int i{ 0 }; i < city[e].size(); i++)
	{
		cout << city[e][i] << " ";
	}
}