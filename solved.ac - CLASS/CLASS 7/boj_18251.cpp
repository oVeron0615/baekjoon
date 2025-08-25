#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = (1 << 18);
const ll INF = 1e18;
int N;
ll tree[SZ];
vector<ll> sum;

void DFS(int u, int y1, int y2)
{
	if(u >= SZ) return;

	DFS(u*2, y1, y2);
	if((1 << y1) <= u && u < (1 << y2))
		sum.push_back(sum.back() + tree[u]);
	DFS(u*2+1, y1, y2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> tree[i];

	int y=0;
	while((1 << y) - 1 != N) y++;

	ll ans = -INF;
	for(int y1=0; y1<y; y1++)
	{
		for(int y2=y1+1; y2<=y; y2++)
		{
			sum.clear();
			sum.push_back(0);
			DFS(1, y1, y2);

			ll mx = -INF, mn = 0;
			for(int i=1; i<sum.size(); i++)
			{
				mx = max(mx, sum[i] - mn);
				mn = min(mn, sum[i]);
			}
			ans = max(ans, mx);
		}
	}
	cout << ans;
} 