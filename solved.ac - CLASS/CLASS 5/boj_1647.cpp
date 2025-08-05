#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
int N, M;
vector<tuple<int, int, int>> edge;
int par[MAXN], height[MAXN];

int Find(int u)
{
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

void Union(int u, int v)
{
	u = Find(u), v = Find(v);
	if(height[u] < height[v]) swap(u, v);
	par[v] = u;
	if(height[u] == height[v]) height[u]++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	while(M--)
	{
		int A, B, C; cin >> A >> B >> C;
		edge.push_back({C, A, B});
	}
	sort(edge.begin(), edge.end());

	for(int i=1; i<=N; i++) par[i] = i;

	int ans = 0;
	int nodeCnt = 1;
	for(auto [d, u, v] : edge)
	{
		if(nodeCnt == N-1) break;
		if(Find(u) == Find(v)) continue;
		Union(u, v);
		ans += d; nodeCnt++;
	}
	cout << ans;
}