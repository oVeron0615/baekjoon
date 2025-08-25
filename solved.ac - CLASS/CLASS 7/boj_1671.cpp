#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;
int N;
tuple<int, int, int> shark[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];
int match[MAXN];

bool DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[match[v]]) continue;
		if(!match[v] || DFS(match[v]))
		{
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		int sz, sp, it; cin >> sz >> sp >> it;
		shark[i] = {sz, sp, it};
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(i == j) continue;
			auto [szi, spi, iti] = shark[i];
			auto [szj, spj, itj] = shark[j];

			if(szi == szj && spi == spj && iti == itj) //a->b, b->a 중 하나의 간선만 남긴다.
			{
				if(i < j) graph[i].push_back(j);
			}
			else if(szi >= szj && spi >= spj && iti >= itj) 
			{
				graph[i].push_back(j);
			}
		}
	}

	int ans = N;
	for(int u=1; u<=N; u++) //두 정점 집합은 같지만 사이클이 없으므로 이분 매칭을 사용할 수 있다.
	{
		memset(vis, false, sizeof(vis));
		if(DFS(u)) ans--;
		memset(vis, false, sizeof(vis));
		if(DFS(u)) ans--;
	}
	cout << ans;
} 