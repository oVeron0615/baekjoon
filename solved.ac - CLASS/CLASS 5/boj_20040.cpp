#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 500001;
int n, m;
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

	cin >> n >> m;
	for(int i=0; i<n; i++) par[i] = i;

	int ans = 0;
	for(int i=1; i<=m; i++)
	{
		int u, v; cin >> u >> v;
		if(Find(u) == Find(v)) 
		{
			if(ans == 0) ans = i;
		}
		else Union(u, v);
	}
	cout << ans;
}