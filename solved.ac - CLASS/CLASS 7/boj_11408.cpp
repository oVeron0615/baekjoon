#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 810, INF = 1e9;
struct edge
{
	int v, cost, cap, rIdx;
};
vector<edge> graph[SZ];
int S = 801, T = 802;
int N, M;

int dist[SZ], prev_v[SZ], prev_e[SZ];
bool inQueue[SZ];
queue<int> qu;

void makeGraph(int u, int v, int cost, int cap)
{
	edge uv = {v, cost, cap, int(graph[v].size())};
	edge vu = {u, -cost, 0, int(graph[u].size())};
	graph[u].push_back(uv);
	graph[v].push_back(vu);
}

bool SPFA()
{
	fill(&dist[0], &dist[0] + SZ, INF);
	dist[S] = 0;
	qu.push(S); inQueue[S] = true;

	while(!qu.empty())
	{
		int u = qu.front(); qu.pop();
		inQueue[u] = false;

		for(int i=0; i<graph[u].size(); i++)
		{
			auto [v, cost, cap, rIdx] = graph[u][i];
			if(cap == 0) continue;

			if(dist[v] > dist[u] + cost)
			{
				dist[v] = dist[u] + cost;
				prev_v[v] = u, prev_e[v] = i;

				if(!inQueue[v])
				{
					qu.push(v);
					inQueue[v] = true;
				}
			}
		}
	}

	return dist[T] != INF;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int u=1; u<=N; u++)
	{
		int n; cin >> n;
		while(n--)
		{
			int v, cost; cin >> v >> cost;
			makeGraph(u, v + N, cost, 1);
		}
	}

	for(int u=1; u<=N; u++) makeGraph(S, u, 0, 1);
	for(int u=1; u<=M; u++) makeGraph(u + N, T, 0, 1);

	int workCnt = 0, minCost = 0;
	while(SPFA())
	{
		int fl = INF;

		for(int v=T; v!=S; v=prev_v[v])
			fl = min(fl, graph[prev_v[v]][prev_e[v]].cap);
		
		for(int v=T; v!=S; v=prev_v[v])
		{
			graph[prev_v[v]][prev_e[v]].cap -= fl;
			graph[v][graph[prev_v[v]][prev_e[v]].rIdx].cap += fl;
		}

		workCnt += fl;
		minCost += fl * dist[T];
	}
	cout << workCnt << "\n" << minCost;
} 