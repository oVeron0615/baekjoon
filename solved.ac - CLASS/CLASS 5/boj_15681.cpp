#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
int N, R, Q; 
vector<int> graph[MAXN];
bool vis[MAXN];
int cnt[MAXN];

void DFS(int u)
{
	vis[u] = true; cnt[u] = 1;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(v); cnt[u] += cnt[v];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> R >> Q;
	for(int i=1; i<N; i++)
	{
		int U, V; cin >> U >> V;
		graph[U].push_back(V);
		graph[V].push_back(U);
	}

	DFS(R);

	while(Q--)
	{
		int U; cin >> U;
		cout << cnt[U] << "\n";
	}
}