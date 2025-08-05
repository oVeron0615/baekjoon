#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	const int MAXN = 100001, INF = 1e9;
	ll psum[MAXN] = {};

	int N, S; cin >> N >> S;
	for(int i=1; i<=N; i++)
	{
		ll num; cin >> num;
		psum[i] = psum[i-1] + num;
	}

	int ans = INF;
	int l = 0;
	for(int r=1; r<=N; r++)
	{
		while(l < r && psum[r] - psum[l] >= S)
		{
			ans = min(ans, r - l);
			l++;
		}
	}

	if(ans == INF) cout << 0;
	else cout << ans;
}