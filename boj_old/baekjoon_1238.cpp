#include <iostream>
#include <vector>
#define inf 1e18
using namespace std;

int main()
{
	int N, M, X; cin >> N >> M >> X;
	vector<vector<long long>> dist(1001, vector<long long>(1001, inf));

	for (int i{ 1 }; i <= N; i++) dist[i][i] = 0;
	for (int i{ 1 }; i <= M; i++)
	{
		long long u, v, t; cin >> u >> v >> t;
		dist[u][v] = min(dist[u][v], t);
	}

	for (int k{ 1 }; k <= N; k++)
	{
		for (int i{ 1 }; i <= N; i++)
		{
			for (int j{ 1 }; j <= N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	long long mx{ 0 };
	for (int i{ 1 }; i <= N; i++)
	{
		mx = max(mx, dist[i][X] + dist[X][i]);
	}
	cout << mx;
}