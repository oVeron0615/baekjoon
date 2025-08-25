#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 400'001;
int N, M;
ll segTree[SZ], lazy[SZ];

void setLazy(int node, int s, int e)
{
	ll val = lazy[node];
	lazy[node] = 0;

	if(s != e)
	{
		lazy[node*2] += val;
		lazy[node*2+1] += val;
	}
	else segTree[node] += val;
}

void update(int node, int s, int e, int l, int r, ll val)
{
	if(lazy[node]) setLazy(node, s, e);

	if(e < l || r < s) return;
	if(l <= s && e <= r)
	{
		if(s != e)
		{
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		else segTree[node] += val;
		return;
	}

	update(node*2, s, (s+e)/2, l, r, val);
	update(node*2+1, (s+e)/2+1, e, l, r, val);
}

ll getVal(int node, int s, int e, int idx)
{
	if(lazy[node]) setLazy(node, s, e);

	if(e < idx || idx < s) return 0;
	if(s == e) return segTree[node];

	return getVal(node*2, s, (s+e)/2, idx) + getVal(node*2+1, (s+e)/2+1, e, idx);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int Ai; cin >> Ai;
		update(1, 1, N, i, i, Ai);
	}

	cin >> M;
	while(M--)
	{
		int order; cin >> order;
		if(order == 1)
		{
			ll i, j, k; cin >> i >> j >> k;
			update(1, 1, N, i, j, k);
		}
		else
		{
			int x; cin >> x;
			cout << getVal(1, 1, N, x) << "\n";
		}
	}
} 