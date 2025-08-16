#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 201, INF = 1e9;
int dist[MAXN][MAXN];
vector<tuple<int, int, int>> edge;
int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, INF);

	cin >> N >> M;
	while(M--)
	{
		int S, E, L; cin >> S >> E >> L;
		edge.push_back({S, E, L});
		dist[S][E] = min(dist[S][E], L);
		dist[E][S] = min(dist[E][S], L);
	}
	for(int i=1; i<=N; i++) dist[i][i] = 0;

	for(int k=1; k<=N; k++)
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	double ans = INF;
	for(int s=1; s<=N; s++)
	{
		double burnTime = 0;
		for(auto [u, v, d] : edge)
		{
			int t = max(dist[s][u], dist[s][v]) - min(dist[s][u], dist[s][v]);
			burnTime = max(burnTime, max(dist[s][u], dist[s][v]) + (d - t) / 2.0);
		}
		ans = min(ans, burnTime);
	}
	cout << fixed << setprecision(1) << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 201, INF = 1e9;
vector<pii> graph[MAXN];
int dist[MAXN];
int N, M;

void dijkstra(int S)
{
	fill(&dist[0], &dist[0] + MAXN, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[S] = 0; pq.push({dist[S], S});

	while(!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if(du > dist[u]) continue;

		for(auto [dv, v] : graph[u])
		{
			if(dist[v] > du + dv)
			{
				dist[v] = du + dv;
				pq.push({dist[v], v});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	while(M--)
	{
		int S, E, L; cin >> S >> E >> L;
		graph[S].push_back({L, E});
		graph[E].push_back({L, S});
	}

	double ans = INF;
	for(int S=1; S<=N; S++)
	{
		dijkstra(S);

		double burnTime = 0;
		for(int u=1; u<=N; u++)
		{
			for(auto [d, v] : graph[u])
			{
				int t = max(dist[u], dist[v]) - min(dist[u], dist[v]);
				burnTime = max(burnTime, max(dist[u], dist[v]) + (d - t) / 2.0);
			}
		}

		ans = min(ans, burnTime);
	}
	cout << fixed << setprecision(1) << ans;
}
*/