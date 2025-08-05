#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 4001;
	int A[MAXN], B[MAXN], C[MAXN], D[MAXN];

	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

	vector<int> AB, CD;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			AB.push_back(A[i] + B[j]), CD.push_back(C[i] + D[j]);
	
	sort(CD.begin(), CD.end());

	ll ans = 0;
	for(int ab : AB) ans += upper_bound(CD.begin(), CD.end(), -ab)
							- lower_bound(CD.begin(), CD.end(), -ab);
	cout << ans;
}