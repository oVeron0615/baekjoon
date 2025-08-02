#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
int N, K;
queue<pii> qu;
int dist[MAXN], path[MAXN];

void f(int u, int v, int d)
{
	if(dist[v] == -1) 
		dist[v] = dist[u] + 1, qu.push({v, dist[v]}), path[v] = path[u];
	else if(dist[v] == d + 1) path[v] += path[u];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> K;
	fill(&dist[0], &dist[0] + MAXN, -1);

	qu.push({N, 0}), dist[N] = 0, path[N] = 1;
	while(!qu.empty())
	{
		auto [u, d] = qu.front(); qu.pop();
		if(u < MAXN-1) f(u, u+1, d);
		if(u > 0) f(u, u-1, d);
		if(u > 0 && u <= MAXN/2) f(u, u*2, d);
	}

	cout << dist[K] << "\n" << path[K];
}