#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int N, M;

int main()
{
	cin >> N >> M;
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	for (int i{ 1 }; i <= N; i++) dist[i][i] = 0;
	for (int i{ 0 }; i < M; i++)
	{
		int a, b; cin >> a >> b;
		dist[a][b] = 1;
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

	int ans{ 0 };
	for (int k{ 1 }; k <= N; k++)
	{
		int cnt{ 0 };
		for (int i{ 1 }; i <= N; i++)
		{
			if (dist[i][k] != 0 && dist[i][k] < INF) cnt++;
			if (dist[k][i] != 0 && dist[k][i] < INF) cnt++;
		}
		if (cnt == N - 1) ans++;
	}
	cout << ans;
}