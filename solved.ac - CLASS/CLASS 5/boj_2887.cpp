#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
int N;
vector<pii> X, Y, Z;
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

	cin >> N;
	for(int i=0; i<N; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		X.push_back({x, i});
		Y.push_back({y, i});
		Z.push_back({z, i});
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for(int i=1; i<N; i++)
	{
		edge.push_back({X[i].first - X[i-1].first, X[i].second, X[i-1].second});
		edge.push_back({Y[i].first - Y[i-1].first, Y[i].second, Y[i-1].second});
		edge.push_back({Z[i].first - Z[i-1].first, Z[i].second, Z[i-1].second});
	}
	sort(edge.begin(), edge.end());

	for(int i=0; i<N; i++) par[i] = i;

	int ans = 0;
	for(auto [d, u, v] : edge)
	{
		if(Find(u) == Find(v)) continue;
		Union(u, v);
		ans += d;
	}
	cout << ans;
}