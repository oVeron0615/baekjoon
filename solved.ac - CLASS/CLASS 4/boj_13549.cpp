#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K; cin >> N >> K;

	const int MAXN = 100001;
	int dist[MAXN];
	fill(&dist[0], &dist[0] + MAXN, 1e9);

	deque<int> dq;
	dq.push_back(N), dist[N] = 0;

	while(!dq.empty())
	{
		int u = dq.front(); dq.pop_front();
		if(u-1 >= 0 && dist[u-1] > dist[u] + 1) dq.push_back(u-1), dist[u-1] = dist[u] + 1;
		if(u+1 <= MAXN-1 && dist[u+1] > dist[u] + 1) dq.push_back(u+1), dist[u+1] = dist[u] + 1;
		if(u*2 <= MAXN-1 && dist[u*2] > dist[u]) dq.push_front(u*2), dist[u*2] = dist[u];
	}
	cout << dist[K];
}