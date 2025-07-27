#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<vector<long long>> dist(101, vector<long long>( 101, 1e10 ));

	int n, m; cin >> n >> m;
	for (int i{ 0 }; i < m; i++)
	{
		long long a, b, c; cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int i{ 1 }; i <= n; i++) dist[i][i] = 0;

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
			if(dist[i][j] == 1e10) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}