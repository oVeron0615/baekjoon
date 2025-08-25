#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 100'001;
int N, M;
ll segTree[SZ * 4];
pii q1[SZ];
vector<tuple<int, int, int>> q2[SZ];

void update(int node, int s, int e, int idx, ll val)
{
	if(e < idx || idx < s) return;
	if(s == e)
	{
		segTree[node] = val;
		return;
	}

	update(node*2, s, (s+e)/2, idx, val);
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll getVal(int node, int s, int e, int l, int r)
{
	if(e < l || r < s) return 0;
	if(l <= s && e <= r) return segTree[node];

	return getVal(node*2, s, (s+e)/2, l, r) + getVal(node*2+1, (s+e)/2+1, e, l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int Ai; cin >> Ai;
		update(1, 1, N, i, Ai);
	}

	int idx = 0;
	cin >> M;
	for(int q=1; q<=M; q++)
	{
		int order; cin >> order;
		if(order == 1)
		{
			ll i, v; cin >> i >> v;
			q1[++idx] = {i, v};
		}
		else
		{
			ll k, i, j; cin >> k >> i >> j;
			q2[k].push_back({i, j, q});
		}
	}

	vector<pll> ans;
	for(int a=0; a<=idx; a++)
	{
		auto [i, v] = q1[a];
		update(1, 1, N, i, v);

		for(auto [i, j, q] : q2[a])
			ans.push_back({q, getVal(1, 1, N, i, j)});
	}
	sort(ans.begin(), ans.end());

	for(auto [q, a] : ans) cout << a << "\n";
} 