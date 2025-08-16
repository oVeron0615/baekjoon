#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, INF = 1e9;
int N, M;
pii segTree[MAXN * 4];

void update(int node, int s, int e, int idx, pii val)
{
	if(idx < s || e < idx) return;
	if(s == e)
	{
		segTree[node] = val;
		return;
	}

	update(node*2, s, (s+e)/2, idx, val); 
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = min(segTree[node*2], segTree[node*2+1]);
}

pii getVal(int node, int s, int e, int l, int r)
{
	if(r < s || e < l) return {INF, INF};
	if(l <= s && e <= r) return segTree[node];

	return min(getVal(node*2, s, (s+e)/2, l, r), getVal(node*2+1, (s+e)/2+1, e, l, r));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) 
	{
		ll Ai; cin >> Ai;
		update(1, 1, N, i, {Ai, i});
	}

	cin >> M;
	while(M--)
	{
		ll order, i, j; cin >> order >> i >> j;
		if(order == 1) update(1, 1, N, i, {j, i});
		else cout << getVal(1, 1, N, i, j).second << "\n";
	}
}