#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
int N;
vector<pii> plate, bridge;
int segTree[MAXN*4];

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
	segTree[node] = max(segTree[node*2], segTree[node*2+1]);
}

int getVal(int node, int s, int e, int l, int r)
{
	if(e < l || r < s) return 0;
	if(l <= s && e <= r) return segTree[node];

	return max(getVal(node*2, s, (s+e)/2, l, r), getVal(node*2+1, (s+e)/2+1, e, l, r));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int l, r; cin >> l >> r;
		plate.push_back({l, r});
	}
	sort(plate.begin(), plate.end());

	int S = 0, E = 0;
	int jump = 0;
	int ans = 0;
	for(auto [l, r] : plate)
	{
		if(l > jump) break;

		if(E < l) S = l, E = r;
		E = max(E, r);
		ans = max(ans, r);
		jump = max(jump, 2*E-S);
	}
	cout << ans;
}