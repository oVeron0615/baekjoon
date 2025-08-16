#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
const ll INF = 1e18;
int N, D;
ll K[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> D;
	for(int i=1; i<=N; i++) cin >> K[i];

	ll ans = -INF;
	priority_queue<pll> pq;
	for(int i=1; i<=N; i++)
	{
		while(!pq.empty() && pq.top().second < i-D) pq.pop();
		ll val = K[i];
		if(!pq.empty()) val = max(val, pq.top().first + K[i]);
		pq.push({val, i});

		ans = max(ans, val);
	}
	cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
const ll INF = 1e18;
int N, D;
ll K[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> D;
	for(int i=1; i<=N; i++) cin >> K[i];

	ll ans = -INF;
	deque<pll> dq;
	for(int i=1; i<=N; i++)
	{
		while(!dq.empty() && dq.front().second < i-D) dq.pop_front();
		ll val = K[i];
		if(!dq.empty()) val = max(val, dq.front().first + K[i]);
		while(!dq.empty() && dq.back().first <= val) dq.pop_back();
		dq.push_back({val, i});

		ans = max(ans, val);
	}
	cout << ans;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
const ll INF = 1e18;
int N, D;
ll K[MAXN];
ll segTree[MAXN * 4];

void update(int node, int s, int e, int idx, ll val)
{
	if(idx < s || e < idx) return;
	if(s == e)
	{
		segTree[node] = val;
		return;
	}

	update(node*2, s, (s+e)/2, idx, val);
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = max(segTree[node*2], segTree[node*2+1]);
}

ll getVal(int node, int s, int e, int l, int r)
{
	if(r < s || e < l) return 0;
	if(l <= s && e <= r) return segTree[node];

	return max(getVal(node*2, s, (s+e)/2, l, r), getVal(node*2+1, (s+e)/2+1, e, l, r));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> D;
	for(int i=1; i<=N; i++) cin >> K[i];

	fill(&segTree[0], &segTree[0] + MAXN * 4, -INF);

	ll ans = -INF;
	for(int i=1; i<=N; i++)
	{
		ll res = max(getVal(1, 1, N, max(1, i-D), i-1), (ll)0) + K[i];
		update(1, 1, N, i, res);
		ans = max(ans, res);
	}
	cout << ans;
}
*/