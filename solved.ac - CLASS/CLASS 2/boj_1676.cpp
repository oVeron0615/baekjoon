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

	int N; cin >> N;
	int cnt2 = 0, cnt5 = 0;
	for(int n=1; n<=N; n++)
	{
		int tmpN = n;
		while(tmpN % 2 == 0) tmpN /= 2, cnt2++;
		while(tmpN % 5 == 0) tmpN /= 5, cnt5++;
	}
	cout << min(cnt2, cnt5);
}