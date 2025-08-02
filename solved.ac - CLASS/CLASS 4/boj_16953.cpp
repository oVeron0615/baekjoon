#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int A, B; cin >> A >> B;
	int ans = 1;
	while(A != B)
	{
		if(B != 0 && B % 2 == 0) B /= 2, ans++;
		else if(B % 10 == 1) B /= 10, ans++;
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}