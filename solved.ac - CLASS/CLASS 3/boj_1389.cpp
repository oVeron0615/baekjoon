#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> graph[101];

	int N, M; cin >> N >> M;
	while(M--)
	{
		int A, B; cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	int minD = 1e9, ans;
	for(int i=1; i<=N; i++)
	{
		queue<int> qu;
		bool vis[101] = {};
		int dist[101] = {};
		qu.push(i); vis[i] = true; dist[i] = 0;

		while(!qu.empty())
		{
			int u = qu.front(); qu.pop();
			for(int v : graph[u])
			{
				if(vis[v]) continue;
				qu.push(v); vis[v] = true; dist[v] = dist[u] + 1;
			}
		}

		int sumD = 0;
		for(int j=1; j<=N; j++) sumD += dist[j];
		if(minD > sumD) minD = sumD, ans = i;
	}
	cout << ans;
}