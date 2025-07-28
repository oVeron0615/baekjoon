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
	vector<pii> points(N);

	for(int i=0; i<N; i++)
	{
		int x, y; cin >> x >> y;
		points[i] = {y, x};
	}
	sort(points.begin(), points.end());

	for(auto [y, x] : points) cout << x << " " << y << "\n";
}