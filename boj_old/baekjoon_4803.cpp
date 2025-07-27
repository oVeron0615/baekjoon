#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N{ 0 };
	while (true)
	{
		N++;

		int n, m; cin >> n >> m;
		if (n == 0 && m == 0) break;

		vector<int> tree[501];
		for (int i{ 0 }; i < m; i++)
		{
			int u, v; cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		queue<pair<int, int>> qu;
		bool vis[501] = {};
		int cnt{ 0 };
		for (int i{ 1 }; i <= n; i++)
		{
			if (!vis[i])
			{
				cnt++;
				bool check{};
				qu.push({ i, 0 });
				vis[i] = true;
				while (!qu.empty())
				{
					auto [p, q] = qu.front(); qu.pop();
					
					for (int j{ 0 }; j < tree[p].size(); j++)
					{
						int next = tree[p][j];
						if (next == q) continue;
						else if (vis[next] || next == p) check = true;
						else
						{
							qu.push({ next, p });
							vis[next] = true;
						}
					}
				}
				if (check) cnt--;
			}
		}

		if (cnt == 0) cout << "Case " << N << ": No trees.\n";
		else if (cnt == 1) cout << "Case " << N << ": There is one tree.\n";
		else cout << "Case " << N << ": A forest of " << cnt << " trees.\n";
	}
}