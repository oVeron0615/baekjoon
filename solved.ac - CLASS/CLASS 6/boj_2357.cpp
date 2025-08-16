#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, INF = 1e9;
pii segTree[MAXN * 4];
int N, M;

void update(int node, int s, int e, int idx, int val)
{
	if(idx < s || e < idx) return;
	if(s == e)
	{
		segTree[node] = {val, val};
		return;
	}

	update(node*2, s, (s+e)/2, idx, val);
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node].first = min(segTree[node*2].first, segTree[node*2+1].first);
	segTree[node].second = max(segTree[node*2].second, segTree[node*2+1].second);
}

pii getVal(int node, int s, int e, int l, int r)
{
	if(e < l || r < s) return {INF, -INF};
	if(l <= s && e <= r) return segTree[node];

	auto [min1, max1] = getVal(node*2, s, (s+e)/2, l, r);
	auto [min2, max2] = getVal(node*2+1, (s+e)/2+1, e, l, r);
	return {min(min1, min2), max(max1, max2)};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++) 
	{
		int num; cin >> num;
		update(1, 1, N, i, num);
	}

	while(M--)
	{
		int a, b; cin >> a >> b;
		auto [mn, mx] = getVal(1, 1, N, a, b);
		cout << mn << " " << mx << "\n";
	}
}