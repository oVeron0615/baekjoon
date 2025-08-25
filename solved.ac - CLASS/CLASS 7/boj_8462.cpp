#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, MAXT = 100'001, MAXA = 1'000'001;
int n, t;
ll a[MAXN], K[MAXA];
ll sum = 0;
ll ans[MAXT];

struct query
{
	int l, r, q;
};
vector<query> Q;
int block;

void add(int s) { sum += (2*K[s] - 1) * s; }
void remove(int s) { sum -= (2*K[s] + 1) * s; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> t;
	block = int(sqrt(n));

	for(int i=1; i<=n; i++) cin >> a[i];
	for(int q=1; q<=t; q++)
	{
		int l, r; cin >> l >> r;
		Q.push_back({l, r, q});
	}

	sort(Q.begin(), Q.end(), [](query q1, query q2){
		if(q1.l / block != q2.l / block) return q1.l / block < q2.l / block;
		else return q1.r < q2.r;
	});

	
	int curL = 1, curR = 0;
	for(auto [l, r, q] : Q)
	{
		while(curR < r) K[a[++curR]]++, add(a[curR]);
		while(curL > l) K[a[--curL]]++, add(a[curL]);
		while(curR > r) --K[a[curR--]], remove(a[curR+1]);
		while(curL < l) --K[a[curL++]], remove(a[curL-1]);

		ans[q] = sum;
	}

	for(int q=1; q<=t; q++) cout << ans[q] << "\n";
}