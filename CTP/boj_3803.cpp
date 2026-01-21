#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 10001;
vector<tuple<int, int, int>> edge;
int V, E;
int par[MAXV], height[MAXV];

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
	
    while(true)
    {
        cin >> V;
        if(V == 0) break;

        edge.clear();
        for(int i=1; i<=V; i++) par[i] = i;
        for(int i=1; i<=V; i++) height[i] = 0;

        cin >> E;
        while(E--)
	    {
	    	int A, B, C; cin >> A >> B >> C;
	    	edge.push_back({C, A, B});
	    }
	    sort(edge.begin(), edge.end());
    
	    int ans = 0;
	    for(auto [d, u, v] : edge)
	    {
	    	if(Find(u) == Find(v)) continue;
	    	Union(u, v);
	    	ans += d;
	    }
	    cout << ans << "\n";
    }
}