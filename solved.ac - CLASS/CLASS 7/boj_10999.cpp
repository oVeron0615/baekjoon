#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 4'000'001;
int N, M, K;
ll segTree[SZ], lazy[SZ];

void setLazy(int node, int s, int e)
{
	ll val = lazy[node];
	lazy[node] = 0; //해당 노드를 이제 업데이트하므로 lazy 값을 없앤다.
	segTree[node] += (e-s+1) * val;

	if(s != e) //리프 노드가 아니라면 자식 노드들에게 갱신할 값을 lazy에 저장, 나중에 갱신한다.
	{
		lazy[node*2] += val;
		lazy[node*2+1] += val;
	}
}

void update(int node, int s, int e, int l, int r, ll val)
{
	if(lazy[node]) setLazy(node, s, e); //node에 미뤄둔 갱신 값이 있으면 업데이트
	if(e < l || r < s) return;
	if(l <= s && e <= r)
	{
		segTree[node] += (e-s+1) * val; //구간 합 갱신
		if(s != e) //리프 노드가 아니라면 자식 노드들에게 갱신할 값을 lazy에 저장, 나중에 갱신한다.
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
	if(lazy[node]) setLazy(node, s, e); //node에 미뤄둔 갱신 값이 있으면 업데이트
	if(e < l || r < s) return 0;
	if(l <= s && e <= r) return segTree[node];

	return getVal(node*2, s, (s+e)/2, l, r) + getVal(node*2+1, (s+e)/2+1, e, l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for(int i=1; i<=N; i++)
	{
		ll num; cin >> num;
		update(1, 1, N, i, i, num);
	}

	for(int i=1; i<=M+K; i++)
	{
		int a; cin >> a;
		if(a == 1)
		{
			ll b, c, d; cin >> b >> c >> d;
			update(1, 1, N, b, c, d);
		}
		else
		{
			ll b, c; cin >> b >> c;
			cout << getVal(1, 1, N, b, c) << "\n";
		}
	}
} 