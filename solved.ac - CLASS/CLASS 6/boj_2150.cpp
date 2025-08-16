#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 10'001;
vector<int> graphf[MAXV], graphr[MAXV];
bool visf[MAXV], visr[MAXV];
int V, E;
stack<int> st;
vector<vector<int>> SCC;

void DFSf(int u)
{
	visf[u] = true;
	for(int v : graphf[u])
	{
		if(visf[v]) continue;
		DFSf(v);
	}
	st.push(u); //DFS 방문 순서대로 stack의 위에 위치하게 된다.
}

void DFSr(int u)
{
	visr[u] = true;
	SCC.back().push_back(u);
	for(int v : graphr[u])
	{
		if(visr[v]) continue;
		DFSr(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;
	while(E--)
	{
		int u, v; cin >> u >> v;
		graphf[u].push_back(v); //정방향 그래프
		graphr[v].push_back(u); //역방향 그래프
	}

	for(int i=1; i<=V; i++)
	{
		if(visf[i]) continue;
		DFSf(i);
	}

	//stack에 있는 정점 순대로 역방향 그래프를 DFS 탐색한다.
	//이런 식으로 탐색할 경우, 역방향 그래프에서 각 정점이 탐색 가능한 범위는 SCC밖에 없다.
	while(!st.empty())
	{
		int u = st.top(); st.pop();
		if(visr[u]) continue;

		SCC.push_back(vector<int>());
		DFSr(u);
		sort(SCC.back().begin(), SCC.back().end());
	}
	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << "\n";
	for(auto scc : SCC)
	{
		for(int u : scc) cout << u << " ";
		cout << -1 << "\n";
	}
}