#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 100001;
int g[SZ];
int par[SZ];
int G, P;

int Find(int u)
{
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> G >> P;
	for(int i=1; i<=P; i++) cin >> g[i];

	for(int i=1; i<=G; i++) par[i] = i;
	
	int ans = 0;
	for(int i=1; i<=P; i++)
	{
		int p = Find(g[i]);
		if(p == 0) break;
		par[p] = Find(par[p-1]);
		ans++;
	}
	cout << ans;
}