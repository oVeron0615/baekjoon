#include <iostream>
#include <vector>
#define inf 1e9
using namespace std;

int main()
{
	int n, m, r; cin >> n >> m >> r;
	int item[101];
	for (int i{ 1 }; i <= n; i++) cin >> item[i];
	vector<vector<int>> dist(101, vector<int>(101, inf));
	for (int i{ 1 }; i <= n; i++) dist[i][i] = 0;
	for (int i{ 1 }; i <= r; i++)
	{
		int u, v, d; cin >> u >> v >> d;
		dist[u][v] = d; dist[v][u] = d;
	}

	for (int k{ 1 }; k <= n; k++)
	{
		for (int i{ 1 }; i <= n; i++)
		{
			for (int j{ 1 }; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i{ 1 }; i <= n; i++)
	{
		for (int j{ 1 }; j <= n; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	int mx{ 0 };
	for (int i{ 1 }; i <= n; i++)
	{
		int cnt{ 0 };
		for (int j{ 1 }; j <= n; j++)
		{
			if (m >= dist[i][j]) cnt += item[j];
		}
		mx = max(mx, cnt);
	}
	cout << mx;
}