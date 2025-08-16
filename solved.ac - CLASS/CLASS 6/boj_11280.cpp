#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10'001;
vector<int> graph[MAXN * 2];
vector<int> rgraph[MAXN * 2];
bool vis[MAXN * 2];
int N, M;
stack<int> st;
int SCC[MAXN * 2];
int SCC_cnt = 0;

int NOT(int u) { return u <= N ? u + N : u - N; }

void DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(v);
	}
	st.push(u);
}

void rDFS(int u)
{
	vis[u] = true;
	SCC[u] = SCC_cnt;
	for(int v : rgraph[u])
	{
		if(vis[v]) continue;
		rDFS(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	while(M--)
	{
		int i, j; cin >> i >> j;
		if(i < 0) i = -i + N;
		if(j < 0) j = -j + N;
		graph[NOT(i)].push_back(j); graph[NOT(j)].push_back(i);
		rgraph[j].push_back(NOT(i)); rgraph[i].push_back(NOT(j));
	}

	for(int u=1; u<=N*2; u++)
	{
		if(vis[u]) continue;
		DFS(u);
	}

	memset(vis, false, sizeof(vis));
	while(!st.empty())
	{
		int u = st.top(); st.pop();
		if(vis[u]) continue;

		SCC_cnt++;
		rDFS(u);
	}

	for(int u=1; u<=N; u++)
	{
		if(SCC[u] == SCC[NOT(u)])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}