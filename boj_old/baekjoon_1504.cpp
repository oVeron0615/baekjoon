#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
int N, E, v1, v2;
vector<pii> graph[801];
int dist[801];
priority_queue<pii, vector<pii>, greater<>> pq;

int main()
{
	cin >> N >> E;
	for (int i{ 0 }; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	cin >> v1 >> v2;

	for (int i{ 1 }; i <= N; i++) dist[i] = INF;
	dist[1] = 0;
	pq.push({ dist[1], 1 });
	while (!pq.empty())
	{
		auto [c, a] = pq.top(); pq.pop();
		if (dist[a] < c) continue;
		for (auto [c, b] : graph[a])
		{
			if (dist[b] > dist[a] + c)
			{
				dist[b] = dist[a] + c;
				pq.push({ dist[b], b });
			}
		}
	}
	long long d1v1{ dist[v1] }, d1v2{ dist[v2] };

	for (int i{ 1 }; i <= N; i++) dist[i] = INF;
	dist[v1] = 0;
	pq.push({ dist[v1], v1 });
	while (!pq.empty())
	{
		auto [c, a] = pq.top(); pq.pop();
		if (dist[a] < c) continue;
		for (auto [c, b] : graph[a])
		{
			if (dist[b] > dist[a] + c)
			{
				dist[b] = dist[a] + c;
				pq.push({ dist[b], b });
			}
		}
	}
	long long d3v2{ dist[N] }, d2v1{ dist[v2] };

	for (int i{ 1 }; i <= N; i++) dist[i] = INF;
	dist[v2] = 0;
	pq.push({ dist[v2], v2 });
	while (!pq.empty())
	{
		auto [c, a] = pq.top(); pq.pop();
		if (dist[a] < c) continue;
		for (auto [c, b] : graph[a])
		{
			if (dist[b] > dist[a] + c)
			{
				dist[b] = dist[a] + c;
				pq.push({ dist[b], b });
			}
		}
	}
	long long d3v1{ dist[N] }, d2v2{ dist[v1] };

	long long ans = min( d1v1 + d2v1 + d3v1, d1v2 + d2v2 + d3v2 );
	if (ans < INF) cout << ans;
	else cout << -1;
}