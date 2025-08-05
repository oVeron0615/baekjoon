#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 30001, MAXK = 3001;
int candy[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];
int N, M, K;
vector<pii> val_cost;
int dp[MAXN][MAXK];

pii DFS(int u)
{
	int candySum = candy[u], childSum = 1;

	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		auto [candy, child] = DFS(v);
		candySum += candy, childSum += child;
	}
	
	return {candySum, childSum};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for(int i=1; i<=N; i++) cin >> candy[i];
	while(M--)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i=1; i<=N; i++)
	{
		if(vis[i]) continue;
		val_cost.push_back(DFS(i));
	}

	int VC = val_cost.size();
	for(int i=1; i<=VC; i++)
	{
		auto [V, C] = val_cost[i-1];
		for(int j=0; j<K; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j >= C) dp[i][j] = max(dp[i][j], dp[i-1][j-C] + V);
		}
	}
	cout << dp[VC][K-1];
}