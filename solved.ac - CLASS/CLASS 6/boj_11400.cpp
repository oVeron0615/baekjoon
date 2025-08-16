#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 100'001;
vector<int> graph[MAXV];
int DFS_num[MAXV], DFS_min[MAXV];
int DFS_cnt = 0;
int V, E;
vector<pii> ans;

void DFS(int u, int p)
{
	DFS_num[u] = DFS_min[u] = ++DFS_cnt;
	for(int v : graph[u])
	{
		if(v == p) continue;
		if(DFS_num[v]) DFS_min[u] = min(DFS_min[u], DFS_num[v]);
		else
		{
			DFS(v, u);
			DFS_min[u] = min(DFS_min[u], DFS_min[v]);
			if(DFS_num[u] < DFS_min[v])
			{
				if(u < v) ans.push_back({u, v});
				else ans.push_back({v, u});
			} 
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;
	while(E--)
	{
		int A, B; cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	DFS(1, 0);

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto [u, v] : ans) cout << u << " " << v << "\n";
}