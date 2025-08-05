#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, vector<int>> piv;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> A(N);
	for(int i=0; i<N; i++) cin >> A[i];

	vector<tuple<int, int, int>> order;
	int M; cin >> M;
	while(M--)
	{
		int l, r, c; cin >> l >> r >> c;
		order.push_back({l, r, c});
	}

	map<vector<int>, int> dist;
	priority_queue<piv, vector<piv>, greater<piv>> pq;
	dist[A] = 0, pq.push({dist[A], A});
	while(!pq.empty())
	{
		auto [du, u] = pq.top(); pq.pop();
		if(du > dist[u]) continue;

		for(auto [l, r, c] : order)
		{
			vector<int> v = u;
			swap(v[l-1], v[r-1]);

			if(dist.find(v) == dist.end() || dist[v] > dist[u] + c)
			{
				dist[v] = dist[u] + c;
				pq.push({dist[v], v});
			}
		}
	}

	sort(A.begin(), A.end());
	if(dist.find(A) == dist.end()) cout << -1;
	else cout << dist[A];
}