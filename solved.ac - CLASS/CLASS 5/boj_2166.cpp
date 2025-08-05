#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<pll> point(N);
	for(int i=0; i<N; i++)
	{
		ll x, y; cin >> x >> y;
		point[i] = {x, y};
	}

	ll sum = 0;
	for(int i=0; i<N; i++)
	{
		auto [x1, y1] = point[i];
		auto [x2, y2] = point[(i+1)%N];
		sum += x1*y2 - x2*y1;
	}
	cout << fixed << setprecision(1) << abs(sum) / 2.0;
}