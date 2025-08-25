#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int MAXN = 1001;
const ll INF = 1e18;
int N, M, K;
int S, D;
vector<pll> graph[MAXN];
ll dist[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	cin >> S >> D;

	while(M--)
	{
		ll a, b, w; cin >> a >> b >> w;
		graph[a].push_back({w, b});
		graph[b].push_back({w, a});
	}

	fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, INF);
	priority_queue<tll, vector<tll>, greater<tll>> pq;
	dist[0][S] = 0; pq.push({dist[0][S], 0, S});
	while(!pq.empty())
	{
		auto [du, eu, u] = pq.top(); pq.pop();
		if(dist[eu][u] < du || eu == N-1) continue;

		for(auto [dv, v] : graph[u])
		{
			if(dist[eu+1][v] > du + dv)
			{
				dist[eu+1][v] = du + dv;
				pq.push({dist[eu+1][v], eu+1, v});
			}
		}
	}

	ll tax = 0;
	while(true)
	{
		ll ans = INF;
		for(int e=1; e<N; e++)
			ans = min(ans, dist[e][D] + tax * e);
		cout << ans << "\n";

		if(K-- == 0) break;

		ll p; cin >> p;
		tax += p;
	}
} 