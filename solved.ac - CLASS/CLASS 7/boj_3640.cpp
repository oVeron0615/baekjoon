#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2010, INF = INT_MAX;
int N, E;

struct edge
{
	int v, cost, cap, rIdx;
};
vector<edge> graph[SZ];
int S, T;

int dist[SZ], prev_v[SZ], prev_e[SZ];
bool inQueue[SZ];
queue<int> qu;

void init()
{
	for(int i=1; i<=N*2; i++) graph[i].clear();
	memset(dist, 0, sizeof(dist));
	memset(prev_v, 0, sizeof(prev_v));
	memset(prev_e, 0, sizeof(prev_e));
	memset(inQueue, false, sizeof(inQueue));
}

void makeGraph(int u, int v, int cost, int cap)
{
	edge uv = {v, cost, cap, int(graph[v].size())};
	edge vu = {u, -cost, 0, int(graph[u].size())};
	graph[u].push_back(uv);
	graph[v].push_back(vu);
}

bool SPFA()
{
	fill(dist, dist + SZ, INF);
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
void solve()
{
	init();

	S = 1, T = N*2;
	while(E--)
	{
		int a, b, c; cin >> a >> b >> c;
		makeGraph(a+N, b, c, 1);
	}

	for(int u=2; u<N; u++) makeGraph(u, u+N, 0, 1);
	makeGraph(1, 1+N, 0, 2); makeGraph(N, N+N, 0, 2);

	int ans = 0;
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

		ans += fl * dist[T];
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(cin >> N >> E) solve();
}