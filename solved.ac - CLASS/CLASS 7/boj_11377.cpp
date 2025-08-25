#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2010;
int N, M, K;
vector<int> graph[SZ];
bool vis[SZ];
int cap[SZ][SZ]; //간선에 남아 있는 용량
int S = 2001, T = 2002, _K = 0; //S : source, T : sink, _K : 임시 정점

void makeGraph(int u, int v) //정방향, 역방향 간선 설정
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int DFS(int u, int minCap) //u : 현재 정점, minCap : 이 정점까지 오면서 구한, 간선에 유량을 보낼 수 있는 남아있는 최소 용량
{
	vis[u] = true;
	if(u == T) return minCap; //sink까지 왔다면 return

	for(int v : graph[u])
	{
		if(vis[v] || cap[u][v] == 0) continue; //유량을 보낼 수 없다면 무시

		int f = DFS(v, min(minCap, cap[u][v]));
		if(f) //유량을 보낼 수 있다면
		{
			cap[u][v] -= f, cap[v][u] += f; //정방향 간선에는 유량만큼 흐르고, 역방향 간선에는 유량만큼 역류하였다.
			return f;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for(int u=1; u<=N; u++)
	{
		int n; cin >> n;
		while(n--)
		{
			int v; cin >> v;
			makeGraph(u, v+N); cap[u][v+N] = 1;
		}
	}

	makeGraph(S, _K);
	cap[S][_K] = K;
	for(int u=1; u<=N; u++) 
	{
		makeGraph(S, u); cap[S][u] = 1;
		makeGraph(_K, u); cap[_K][u] = 1;
	}

	for(int u=N+1; u<=N+M; u++) 
	{
		makeGraph(u, T); cap[u][T] = 1;
	}

	int ans = 0;
	while(true)
	{
		memset(vis, false, sizeof(vis));

		int f = DFS(S, INT_MAX);
		if(f == 0) break; //더 이상 유량을 흘릴 수 없을 때까지 반복
		ans += f;
	}
	cout << ans;
}