#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1'000'001;
int n;
int segTree[SZ * 4];

void update(int node, int s, int e, int idx, int val)
{
	if(idx < s || e < idx) return;
	if(s == e)
	{
		segTree[node] += val;
		return;
	}

	update(node*2, s, (s+e)/2, idx, val);
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

int getVal(int node, int s, int e, int val) 
{
	if(s == e) return s;
	if(val <= segTree[node*2]) return getVal(node*2, s, (s+e)/2, val);
	else return getVal(node*2+1, (s+e)/2+1, e, val - segTree[node*2]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	while(n--)
	{
		int A; cin >> A;
		if(A == 1)
		{
			int B; cin >> B;
			int candy = getVal(1, 1, SZ-1, B);
			cout << candy << "\n";
			update(1, 1, SZ-1, candy, -1);
		}
		else
		{
			int B, C; cin >> B >> C;
			update(1, 1, SZ-1, B, C);
		}
	}
}