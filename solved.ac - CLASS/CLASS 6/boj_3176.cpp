#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, SP = 17;
const ll INF = 1e18;
vector<pll> graph[MAXN];
int par[SP][MAXN];
ll mxD[SP][MAXN], mnD[SP][MAXN];
int lv[MAXN];
int N, K;

void DFS(int u, int p, int l)
{
	par[0][u] = p, lv[u] = l;
	for(auto [d, v] : graph[u])
	{
		if(v == p) mxD[0][u] = d, mnD[0][u] = d;
		else DFS(v, u, l + 1);
	}
}

pll LCA(int u, int v)
{
	if(lv[u] < lv[v]) swap(u, v);

	ll mxDist = 0, mnDist = INF;
	int d = lv[u] - lv[v];
	for(int i=0; i<SP; i++)
	{
		if(d & (1 << i)) 
		{
			mxDist = max(mxDist, mxD[i][u]);
			mnDist = min(mnDist, mnD[i][u]);
			u = par[i][u];
		}
	}
	
	if(u == v) return {mnDist, mxDist};
	
	for(int i=SP-1; i>=0; i--)
	{
		if(par[i][u] != par[i][v]) 
		{
			mxDist = max(mxDist, max(mxD[i][u], mxD[i][v]));
			mnDist = min(mnDist, min(mnD[i][u], mnD[i][v]));
			u = par[i][u], v = par[i][v];
		}
	}
	
	mxDist = max(mxDist, max(mxD[0][u], mxD[0][v]));
	mnDist = min(mnDist, min(mnD[0][u], mnD[0][v]));
	return {mnDist, mxDist};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<N; i++)
	{
		ll A, B, C; cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}

	DFS(1, 0, 1);

	for(int i=1; i<SP; i++)
	{
		for(int j=1; j<=N; j++)
		{
			par[i][j] = par[i-1][par[i-1][j]];
			mxD[i][j] = max(mxD[i-1][j], mxD[i-1][par[i-1][j]]);
			mnD[i][j] = min(mnD[i-1][j], mnD[i-1][par[i-1][j]]);
		}
	}
	
	cin >> K;
	while(K--)
	{
		int D, E; cin >> D >> E;
		auto [mnAns, mxAns] = LCA(D, E);
		cout << mnAns << " " << mxAns << "\n";
	}
}