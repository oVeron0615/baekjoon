#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 510, INF = INT_MAX;
int N;
int w[SZ][SZ];

struct edge
{
	int v, cap, rIdx;
};
vector<edge> graph[SZ];
int S = 501, T = 502;

bool vis[SZ];
int dist[SZ];
int iter[SZ];

void makeGraph(int u, int v, int cap)
{
	edge uv = {v, cap, int(graph[v].size())};
	edge vu;
	if(cap == INF) vu = {u, 0, int(graph[u].size())};
	else vu = {u, cap, int(graph[u].size())};
	graph[u].push_back(uv);
	graph[v].push_back(vu);
}

bool BFS() //각 정점에 대한 최단경로 구하기
{
	memset(dist, -1, sizeof(dist));
	queue<int> qu;
	dist[S] = 0; qu.push(S);

	while(!qu.empty())
	{
		int u = qu.front(); qu.pop();
		for(auto [v, cap, rIdx] : graph[u])
		{
			if(dist[v] != -1 || cap == 0) continue;
			dist[v] = dist[u] + 1;
			qu.push(v);
		}
	}

	return dist[T] != -1;
}

int DFS(int u, int minCap)
{
	if(u == T) return minCap;

	for(int& i=iter[u]; i<graph[u].size(); i++) //한 번 탐색한 자식은 다시 볼 이유가 없다.
	{
		auto [v, cap, rIdx] = graph[u][i];
		if(dist[v] != dist[u] + 1 || cap == 0) continue;

		int f = DFS(v, min(cap, minCap));
		if(f)
		{
			graph[u][i].cap -= f; graph[v][rIdx].cap += f;
			return f;
		}
	}
	return 0;
}

void makeCut(int u) //컷을 구하고 싶다면, source부터 시작하여 남아있는 용량이 있는 정점을 DFS 탐색하면 된다.
{
	vis[u] = true;
	for(auto [v, cap, rIdx] : graph[u])
	{
		if(vis[v] || cap == 0) continue;
		makeCut(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int u=1; u<=N; u++)
	{
		int num; cin >> num;
		if(num == 1) makeGraph(S, u, INF);
		else if(num == 2) makeGraph(u, T, INF);
	}
	for(int u=1; u<=N; u++)
	{
		for(int v=1; v<=N; v++)
		{
			cin >> w[u][v];
			if(u < v) makeGraph(u, v, w[u][v]);
		}
	}
	
	int ans = 0;
	while(BFS())
	{
		memset(iter, false, sizeof(iter));
		while(true)
		{
			int f = DFS(S, INF);
			if(f == 0) break;
			ans += f;
		}
	}

	makeCut(S);

	cout << ans << "\n";
	for(int u=1; u<=N; u++)
		if(vis[u]) cout << u << " ";
	cout << "\n";
	for(int u=1; u<=N; u++)
		if(!vis[u]) cout << u << " ";
	cout << "\n";
}