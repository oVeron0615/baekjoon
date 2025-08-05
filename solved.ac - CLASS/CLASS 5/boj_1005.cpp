#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
int N, K;
int D[MAXN];
vector<int> graph[MAXN];
int W;
int dp[MAXN];

int DFS(int u)
{
	if(dp[u] != -1) return dp[u];
	dp[u] = 0;
	for(int v : graph[u])
	{
		dp[u] = max(dp[u], DFS(v));
	}
	return dp[u] += D[u];
}

void solve()
{
	fill(&dp[0], &dp[0] + MAXN, -1);
	fill(&graph[0], &graph[0] + MAXN, vector<int>());

	cin >> N >> K;
	for(int i=1; i<=N; i++) cin >> D[i];
	while(K--)
	{
		int X, Y; cin >> X >> Y;
		graph[Y].push_back(X);
	}
	cin >> W;

	cout << DFS(W) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}