#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
	const int MAXN = 501, INF = 1e9;
	vector<pii> graph[MAXN];
	int dist[MAXN] = {};

	int N, M, W; cin >> N >> M >> W;
	while(M--)
	{
		int S, E, T; cin >> S >> E >> T;
		graph[S].push_back({T, E});
		graph[E].push_back({T, S});
	}
	while(W--)
	{
		int S, E, T; cin >> S >> E >> T;
		graph[S].push_back({-T, E});
	}

	for(int t=0; t<=N; t++)
	{
		bool update = false;
		for(int u=0; u<=N; u++)
		{
			for(auto [d, v] : graph[u])
			{
				if(dist[u] != INF && dist[v] > dist[u] + d)
				{
					dist[v] = dist[u] + d;
					update = true;
				}
			}
		}

		if(t == N && update)
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int TC; cin >> TC;
	while(TC--) solve();
}