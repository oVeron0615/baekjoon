#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 100'001;
int n, m;
int segTree[SZ * 8];
int loc[SZ];

void update(int node, int s, int e, int idx, int val)
{
	if(idx < s || e < idx) return;
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
	if(r < s || e < l) return 0;
	if(l <= s && e <= r) return segTree[node];

	return getVal(node*2, s, (s+e)/2, l, r) 
			+ getVal(node*2+1, (s+e)/2+1, e, l, r);
}

void solve()
{
	memset(segTree, 0, sizeof(segTree));

	cin >> n >> m;
	for(int i=1; i<=n; i++) 
	{
		loc[i] = i + m;
		update(1, 1, m+n, loc[i], 1);
	}

	int top = m;
	for(int i=1; i<=m; i++)
	{
		int num; cin >> num;
		update(1, 1, m+n, loc[num], 0);
		cout << getVal(1, 1, m+n, 1, loc[num]-1) << " ";
		update(1, 1, m+n, top, 1);
		loc[num] = top--;
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--) solve();
}