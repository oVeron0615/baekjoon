#include <iostream>
#include <vector>
#include <queue>
#define inf 1e9
using namespace std;

int main()
{
	int T; cin >> T;
	for (int tc{ 0 }; tc < T; tc++)
	{
		typedef pair<double, int> pdi;
		vector<pdi> graph[2001];
		vector<double> cost(2001, inf);
		vector<int> course[2001];

		int n, m, t; cin >> n >> m >> t;
		int s, g, h; cin >> s >> g >> h;
		for (int i{ 0 }; i < m; i++)
		{
			int a, b; cin >> a >> b;
			double d; cin >> d;

			if ((a == g && b == h) || (a == h && b == g)) d -= 0.5;

			graph[a].push_back({ d, b });
			graph[b].push_back({ d, a });
		}

		priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
		pq.push({ 0, s });
		cost[s] = 0;
		course[s].push_back(s);
		while (!pq.empty())
		{
			auto [d, u] = pq.top(); pq.pop();
			if (cost[u] < d) continue;

			for (auto [d, v] : graph[u])
			{
				if (cost[v] > cost[u] + d)
				{
					cost[v] = cost[u] + d;
					pq.push({ cost[v], v });

					course[v].clear();
					for (int i : course[u]) course[v].push_back(i);
					course[v].push_back(v);
				}
			}
		}

		priority_queue<int, vector<int>, greater<int>> pqu;
		for (int i{ 0 }; i < t; i++)
		{
			int x; cin >> x;
			bool check{};
			for (int j{ 1 }; j < course[x].size(); j++)
			{
				if ((course[x][j] == g && course[x][j - 1] == h)
					|| (course[x][j] == h && course[x][j - 1] == g))
				{
					check = true;
					break;
				}
			}

			if (check) pqu.push(x);
		}

		while (!pqu.empty())
		{
			cout << pqu.top() << " ";
			pqu.pop();
		}
		cout << "\n";
	}
}