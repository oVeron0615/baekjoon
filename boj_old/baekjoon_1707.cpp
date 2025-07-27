#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <cstring>
using namespace std;

typedef array<int, 3> arr;

int main()
{
	int K; cin >> K;
	for (int k{ 0 }; k < K; k++)
	{
		vector<int> graph[20001];
		queue<arr> qu;
		bool vis[20001];
		int len[20001];
		bool check{};

		memset(vis, 0, sizeof(vis));
		int V, E; cin >> V >> E;
		for (int i{ 0 }; i < E; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int j{ 1 }; j <= V; j++)
		{
			if (vis[j]) continue;
			qu.push({ j, 0, 0 });
			vis[j] = true; len[j] = 0;

			while (!qu.empty() && !check)
			{
				int a = qu.front()[0], l = qu.front()[1], f = qu.front()[2];
				qu.pop();

				for (int i{ 0 }; i < graph[a].size(); i++)
				{
					int next = graph[a][i];
					if (!vis[next])
					{
						qu.push({ next, l + 1, a });
						vis[next] = true; len[next] = l + 1;
					}
					else
					{
						if (l == len[next] && next != f)
						{
							cout << "NO\n";
							check = true;
							break;
						}
					}
				}
			}
			if (check) break;
		}

		if (!check) cout << "YES\n";
	}
}