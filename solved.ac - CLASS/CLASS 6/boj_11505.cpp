#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1'000'001;
const ll MOD = 1'000'000'007;
int N, M, K;
ll segTree[MAXN * 4];

void update(int node, int s, int e, int idx, ll val)
{
	if(idx < s || e < idx) return;
	if(s == e)
	{
		segTree[node] = val; //값 수정
		return;
	}

	update(node*2, s, (s+e)/2, idx, val); 
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = segTree[node*2] * segTree[node*2+1] % MOD;
}

ll getVal(int node, int s, int e, int l, int r)
{
	if(r < s || e < l) return 1;
	if(l <= s && e <= r) return segTree[node];

	return getVal(node*2, s, (s+e)/2, l, r) 
			* getVal(node*2+1, (s+e)/2+1, e, l, r) % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for(int i=1; i<=N; i++) 
	{
		ll Ai; cin >> Ai;
		update(1, 1, N, i, Ai);
	}

	for(int i=1; i<=M+K; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		if(a == 1) update(1, 1, N, b, c);
		else cout << getVal(1, 1, N, b, c) << "\n";
	}
}