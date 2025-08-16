#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 5001, SZ = 800'001;
	int A[MAXN];
	bool sum[SZ] = {};
	
	int w, n; cin >> w >> n;
	for(int i=1; i<=n; i++) cin >> A[i];

	for(int i=3; i<n; i++)
	{
		for(int j=1; j<i-1; j++) sum[A[i-1] + A[j]] = true;

		int p1 = A[i];
		for(int j=i+1; j<=n; j++)
		{
			if(w - (A[i] + A[j]) < 0) continue;
			if(sum[w - (A[i] + A[j])])
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}