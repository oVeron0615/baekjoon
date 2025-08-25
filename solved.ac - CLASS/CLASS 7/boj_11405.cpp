#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 210, INF = 1e9;
int N, M;
struct edge
{
	int nv, cost, cap, rIdx;
	//다음 정점, 비용, 남은 용량, 역방향 간선(v -> u)이 graph[v]에 저장될 index
};
vector<edge> graph[SZ];
int S = 201, T = 202;

//prev_v[v] : 정점 v의 이전 정점 u, prev_e[v] : v -> u의 역방향 간선 u -> v의 벡터 인덱스, 즉 graph[u]에서 u -> v가 저장된 인덱스
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
			if(cap == 0) continue; //남은 용량이 없으면 유량을 흘릴 수 없으므로 무시

			if(dist[v] > dist[u] + cost)
			{
				dist[v] = dist[u] + cost;
				//현재 정방향 간선 u -> v를 보고 있으니, 이전 정점은 u가 된다.
				//역방향 간선 v -> u에 저장할 역방향 간선의 인덱스는 정방향 간선 u -> v의 인덱스이므로, 이는 곧 i이다.
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
	for(int i=1; i<=N; i++)
	{
		int Ai; cin >> Ai;
		makeGraph(i+M, T, 0, Ai);
	}
	for(int i=1; i<=M; i++)
	{
		int Bi; cin >> Bi;
		makeGraph(S, i, 0, Bi);
	}
	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=N; j++)
		{
			int Cij; cin >> Cij;
			makeGraph(i, M+j, Cij, INF);
		}
	}

	int ans = 0;
	while(SPFA()) //유량을 보낼 수 있는지 확인
	{
		int fl = INF;

		//정방향 간선 u -> v의 남은 용량의 최솟값 찾기
		//prev_v[v] = u, prev_e[v] = 정방향 간선 u -> v의 인덱스
		//graph[prev_v[v]][prev_e[v]].cap : 정방향 간선 u -> v의 남은 용량
		for(int v=T; v!=S; v=prev_v[v]) //sink부터 경로 역추적
			fl = min(fl, graph[prev_v[v]][prev_e[v]].cap); 

		//정방향 간선, 역방향 간선에 유량 보내기
		//graph[prev_v[v]][prev_e[v]].rIdx : 정방향 간선 u -> v의 역방향 간선 v -> u의 인덱스
		//graph[v][graph[prev_v[v]][prev_e[v]].rIdx].cap : 역방향 간선 v -> u의 인덱스
		for(int v=T; v!=S; v=prev_v[v]) 
		{
			graph[prev_v[v]][prev_e[v]].cap -= fl;
			graph[v][graph[prev_v[v]][prev_e[v]].rIdx].cap += fl;
		}

		ans += fl * dist[T];
	}
	cout << ans;
} 