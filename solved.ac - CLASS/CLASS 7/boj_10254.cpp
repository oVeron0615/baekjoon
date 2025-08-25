#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> coord;

int N;
vector<coord> point;

auto cmp = [](coord p1, coord p2)
{
	return p1.real() == p2.real() ? p1.imag() < p2.imag() : p1.real() < p2.real();
};

ll CCW(coord v1, coord v2) { return (conj(v1) * v2).imag(); }
ll dist(coord p1, coord p2) 
{ 
	return (p1.real() - p2.real()) * (p1.real() - p2.real()) + (p1.imag() - p2.imag()) * (p1.imag() - p2.imag()); 
}

void solve()
{
	point.clear();
	cin >> N;
	for(int i=0; i<N; i++)
	{
		ll x, y; cin >> x >> y;
		point.push_back({x, y});
	}
	sort(point.begin(), point.end(), cmp);

	vector<coord> lower, upper;
	for(int i=0; i<N; i++)
	{
		while(lower.size() >= 2 && CCW(lower[lower.size()-1] - lower[lower.size()-2], point[i] - lower[lower.size()-2]) <= 0)
			lower.pop_back();
		lower.push_back(point[i]);
	}
	for(int i=N-1; i>=0; i--)
	{
		while(upper.size() >= 2 && CCW(upper[upper.size()-1] - upper[upper.size()-2], point[i] - upper[upper.size()-2]) <= 0)
			upper.pop_back();
		upper.push_back(point[i]);
	}

	lower.pop_back(), upper.pop_back();

	vector<coord> hull;
	for(coord p : lower) hull.push_back(p);
	for(coord p : upper) hull.push_back(p);
	
	ll mxDist = 0;
	coord ans1, ans2;
	int x = 0, y = lower.size();

	for(int i=0; i<hull.size(); i++)
	{
		coord p1 = hull[x], p2 = hull[(x + 1) % hull.size()];
		coord p3 = hull[y], p4 = hull[(y + 1) % hull.size()];
		
		if(mxDist < dist(hull[x], hull[y]))
		{
			mxDist = dist(hull[x], hull[y]);
			ans1 = hull[x], ans2 = hull[y];
		}

		if(CCW(p2 - p1, p3 - p4) > 0) x = (x+1) % hull.size();
		else y = (y+1) % hull.size();
	}

	cout << ans1.real() << " " << ans1.imag() << " " << ans2.real() << " " << ans2.imag() << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}