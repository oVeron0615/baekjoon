#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 32001;
	vector<int> graph[MAXN];
	int indegree[MAXN] = {};

	int N, M; cin >> N >> M;
	while(M--)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1; i<=N; i++)
		if(indegree[i] == 0) pq.push(i);

	while(!pq.empty())
	{
		int u = pq.top(); pq.pop();
		for(int v : graph[u])
			if(!--indegree[v]) pq.push(v);
		cout << u << " ";
	}
}