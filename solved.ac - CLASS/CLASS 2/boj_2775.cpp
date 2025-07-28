#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--)
	{
		int k, n; cin >> k >> n;
		vector<int> cnt(n+1);
		for(int i=1; i<=n; i++) cnt[i] = i;
		for(int i=1; i<=k; i++)
		{
			int sum = 0;
			for(int j=1; j<=n; j++)
			{
				sum += cnt[j];
				cnt[j] = sum;
			}
		}
		cout << cnt[n] << "\n";
	}
}