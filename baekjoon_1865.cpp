#include <iostream>
#include <vector>
#define inf 1e9
using namespace std;

int main()
{
	typedef pair<int, int> pii;

	int TC; cin >> TC;
	for (int t{ 0 }; t < TC; t++)
	{
		vector<pii> graph[501];
		vector<int> Time(501, inf);

		int N, M, W; cin >> N >> M >> W;
		int S, E, T;
		for (int i{ 0 }; i < M; i++)
		{
			cin >> S >> E >> T;
			graph[S].push_back({ E, T });
			graph[E].push_back({ S, T });
		}
		for (int i{ 0 }; i < W; i++)
		{
			cin >> S >> E >> T;
			graph[S].push_back({ E, -T });
		}

		bool update{};
		for (int k{ 1 }; k <= N; k++)
		{
			update = false;
			for (int i{ 1 }; i <= N; i++)
			{
				for (int j{ 0 }; j < graph[i].size(); j++)
				{
					auto [v, d] = graph[i][j];
					if (Time[v] > Time[i] + d)
					{
						Time[v] = Time[i] + d;
						update = true;
					}
				}
			}
			if (!update) break;
		}

		if (update) cout << "YES\n";
		else cout << "NO\n";
	}
}