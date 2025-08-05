#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 4'000'001;
int N, M, K;
int card[SZ];
int par[SZ], height[SZ];

int Find(int u)
{
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for(int i=1; i<=M; i++) cin >> card[i];
	sort(card + 1, card + M + 1);

	int idx = 1;
	for(int i=1; i<=N; i++)
	{
		if(card[idx] == i) par[i] = i, idx++;
		else par[i] = i+1;
	}

	while(K--)
	{
		int num; cin >> num;
		int ans = Find(par[num+1]);
		cout << ans << "\n";
		par[ans] = ans + 1;
	}
}