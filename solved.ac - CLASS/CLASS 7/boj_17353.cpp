#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 400'002;
int N, Q;
ll A[SZ];
ll segTree[SZ], lazy[SZ];

void setLazy(int node, int s, int e)
{
	int val = lazy[node];
	lazy[node] = 0;
	segTree[node] += (e-s+1) * val;

	if(s != e)
	{
		lazy[node*2] += val;
		lazy[node*2+1] += val;
	}
}

void update(int node, int s, int e, int l, int r, ll val)
{
	if(lazy[node]) setLazy(node, s, e);
	if(e < l || r < s) return;
	if(l <= s && e <= r)
	{
		segTree[node] += (e-s+1) * val;
		if(s != e)
		{
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}

	update(node*2, s, (s+e)/2, l, r, val);
	update(node*2+1, (s+e)/2+1, e, l, r, val);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll getVal(int node, int s, int e, int l, int r)
{ 
	if(lazy[node]) setLazy(node, s, e);
	if(e < l || r < s) return 0;
	if(l <= s && e <= r) return segTree[node];

	return getVal(node*2, s, (s+e)/2, l, r) + getVal(node*2+1, (s+e)/2+1, e, l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	cin >> Q;
	while(Q--)
	{
		int o; cin >> o;
		if(o == 1)
		{
			ll L, R; cin >> L >> R;
			update(1, 1, N, L, R, 1);
			update(1, 1, N, R+1, R+1, -R+L-1);
		}
		else
		{
			int X; cin >> X;
			cout << getVal(1, 1, N, 1, X) + A[X] << "\n";
		}
	}
}