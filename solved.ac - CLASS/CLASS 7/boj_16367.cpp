#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10'001;
vector<int> graph[MAXN * 2];
vector<int> rgraph[MAXN * 2];
bool vis[MAXN * 2];
int k, n;
stack<int> st;
int SCC_num[MAXN * 2];
int SCC_cnt = 0;
vector<vector<int>> SCC;
int ans[MAXN * 2];

int NOT(int u) { return u <= k ? u + k : u - k; }

void makeGraph(int u, int v)
{
	graph[NOT(u)].push_back(v); graph[NOT(v)].push_back(u);
	rgraph[v].push_back(NOT(u)); rgraph[u].push_back(NOT(v));
}

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
	SCC_num[u] = SCC_cnt;
	SCC.back().push_back(u);
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

	cin >> k >> n;
	while(n--)
	{
		int l1, l2, l3; char c1, c2, c3;
		cin >> l1 >> c1 >> l2 >> c2 >> l3 >> c3;
		if(c1 == 'B') l1 += k;
		if(c2 == 'B') l2 += k;
		if(c3 == 'B') l3 += k;

		makeGraph(l1, l2); 
		makeGraph(l2, l3); 
		makeGraph(l3, l1);
	}

	for(int u=1; u<=k*2; u++)
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
		SCC.push_back(vector<int>());
		rDFS(u);
	}

	for(int u=1; u<=k; u++)
	{
		if(SCC_num[u] == SCC_num[NOT(u)])
		{
			cout << -1;
			return 0;
		}
	}

	memset(ans, -1, sizeof(ans));
	for(auto scc : SCC)
	{
		int val = 0;
		for(int u : scc)
		{
			if(ans[u] != -1)
			{
				val = ans[u];
				break;
			}
		}

		for(int u : scc)
			ans[u] = val, ans[NOT(u)] = 1 - val;
	}

	for(int u=1; u<=k; u++) 
	{
		if(ans[u]) cout << "R";
		else cout << "B";
	}
}