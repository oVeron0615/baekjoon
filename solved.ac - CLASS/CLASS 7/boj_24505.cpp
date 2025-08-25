#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, ele = 11;
const ll MOD = 1e9 + 7;
int N;
int A[MAXN];
ll dp[ele+1][MAXN];
ll segTree[MAXN * 4];

void update(int node, int s, int e, int idx, ll val)
{
	if(idx < s || e < idx) return;
	if(s == e)
	{
		segTree[node] = (segTree[node] + val) % MOD;
		return;
	}

	update(node*2, s, (s+e)/2, idx, val);
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = (segTree[node*2] + segTree[node*2+1]) % MOD;
}

ll getVal(int node, int s, int e, int l, int r)
{
	if(e < l || r < s) return 0;
	if(l <= s && e <= r) return segTree[node];

	return (getVal(node*2, s, (s+e)/2, l, r) 
			+ getVal(node*2+1, (s+e)/2+1, e, l, r)) % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		cin >> A[i];
		dp[1][i] = 1;
	}

	for(int i=2; i<=ele; i++)
	{
		memset(segTree, 0, sizeof(segTree));
		for(int j=1; j<=N; j++)
		{
			dp[i][j] = getVal(1, 1, N, 1, A[j]-1);
			update(1, 1, N, A[j], dp[i-1][j]);
		}
	}

	ll ans = 0;
	for(int i=1; i<=N; i++)
		ans = (ans + dp[ele][i]) % MOD;
	cout << ans;
} 