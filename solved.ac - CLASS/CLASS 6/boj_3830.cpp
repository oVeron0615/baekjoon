#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
int N, M;
int par[MAXN], height[MAXN], weight[MAXN];

int Find(int u) //부모 갱신 및 좌표 압축, 거리 갱신
{
	if(par[u] == u) return u;
	int root = Find(par[u]);
	weight[u] += weight[par[u]]; //par[u]의 거리가 갱신되었으므로 u의 거리를 새롭게 구한다.
	return par[u] = root; //par[u]를 root로 정의
}

void Union(int a, int b, int w)
{
	int u = Find(a), v = Find(b);
	if(u == v) return;

	w = weight[a] + w - weight[b]; //a, b의 거리가 갱신되었으므로 w를 새롭게 구한다.
	if(height[u] < height[v]) swap(u, v), w = -w;
	par[v] = u, weight[v] = w;
	if(height[u] == height[v]) height[u]++;
}

void solve()
{
	for(int i=1; i<=N; i++) par[i] = i;
	memset(height, 0, sizeof(height));
	memset(weight, 0, sizeof(weight));

	while(M--)
	{
		char c; cin >> c;
		if(c == '!')
		{
			int a, b, w; cin >> a >> b >> w;
			Union(a, b, w);
		}
		else
		{
			int a, b; cin >> a >> b;
			if(Find(a) == Find(b)) cout << weight[b] - weight[a] << "\n";
			else cout << "UNKNOWN\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(true) 
	{
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		solve();
	}
}

/*
좌표 압축 X
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
int N, M;
int par[MAXN], height[MAXN], weight[MAXN];

int retW(int u)
{
	if(par[u] == u) return 0;
	return weight[u] + retW(par[u]);
}

int Find(int u)
{
	if(par[u] == u) return u;
	return Find(par[u]);
}

void Union(int u, int v, int w)
{
	w = retW(u) + w - retW(v);
	u = Find(u), v = Find(v);
	if(u == v) return;

	if(height[u] < height[v]) swap(u, v), w = -w;
	par[v] = u, weight[v] = w;
	if(height[u] == height[v]) height[u]++;
}

void solve()
{
	for(int i=1; i<=N; i++) par[i] = i;
	memset(height, 0, sizeof(height));
	memset(weight, 0, sizeof(weight));

	while(M--)
	{
		char c; cin >> c;
		if(c == '!')
		{
			int a, b, w; cin >> a >> b >> w;
			Union(a, b, w);
		}
		else
		{
			int a, b; cin >> a >> b;
			if(Find(a) == Find(b)) cout << retW(b) - retW(a) << "\n";
			else cout << "UNKNOWN\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(true) 
	{
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		solve();
	}
}
*/