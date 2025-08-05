#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 32001;
vector<int> graph[MAXN];
bool vis[MAXN];
int N, M;
stack<int> st;

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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	while(M--)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
	}

	for(int i=1; i<=N; i++)
	{
		if(vis[i]) continue;
		DFS(i);
	}

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}