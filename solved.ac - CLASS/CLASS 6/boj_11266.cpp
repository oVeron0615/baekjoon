#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 10'001;
vector<int> graph[MAXV];
int DFS_num[MAXV], DFS_min[MAXV];
int DFS_cnt = 0;
bool isCut[MAXV], isRoot[MAXV];
int childCnt[MAXV];
int V, E;

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
			if(DFS_num[u] <= DFS_min[v]) isCut[u] = true;
			childCnt[u]++;
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

	for(int u=1; u<=V; u++)
	{
		if(!DFS_num[u]) 
		{
			isRoot[u] = true;
			DFS(u, 0);
		}
	}

	//루트이면서 자식이 1개밖에 없다면 단절점이 될 수 없다.
	vector<int> ans;
	for(int u=1; u<=V; u++)
		if(isCut[u] && (!isRoot[u] || childCnt[u] > 1)) ans.push_back(u);

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int a : ans) cout << a << " ";
}