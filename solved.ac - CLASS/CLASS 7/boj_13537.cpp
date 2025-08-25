#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
int A[MAXN];
vector<int> segTree[MAXN * 4];
int N, M;

void build(int node, int s, int e)
{
	if(s == e)
	{
		segTree[node].push_back(A[s]);
		return;
	}

	build(node*2, s, (s+e)/2);
	build(node*2+1, (s+e)/2+1, e);

	vector<int>& lv = segTree[node*2];
	vector<int>& rv = segTree[node*2+1];
	vector<int>& v = segTree[node];
	v.resize(lv.size() + rv.size());
	merge(lv.begin(), lv.end(), rv.begin(), rv.end(), v.begin());
}

int getVal(int node, int s, int e, int l, int r, int k)
{
	if(e < l || r < s) return 0;
	if(l <= s && e <= r)
	{
		vector<int>& v = segTree[node];
		return v.end() - upper_bound(v.begin(), v.end(), k);
	}

	return getVal(node*2, s, (s+e)/2, l, r, k) + getVal(node*2+1, (s+e)/2+1, e, l, r, k);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	build(1, 1, N);

	cin >> M;
	while(M--)
	{
		int i, j, k; cin >> i >> j >> k;
		cout << getVal(1, 1, N, i, j, k) << "\n";
	}
} 