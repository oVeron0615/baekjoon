#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> coord;

auto cmp = [](coord p1, coord p2)
{
	return p1.real() == p2.real() ? p1.imag() < p2.imag() : p1.real() < p2.real();
};

coord vec(coord p1, coord p2) { return p2 - p1; }
double CCW(coord p1, coord p2, coord p3)
{
	coord p12 = vec(p1, p2), p23 = vec(p2, p3);
	return (conj(p12) * p23).imag();
}

double calDist(coord p1, coord p2, coord p3) //점과 직선 사이의 거리
{
	double A = p2.imag() - p3.imag(), B = p3.real() - p2.real(), C = p2.real() * p3.imag() - p3.real() * p2.imag();
	return abs(A * p1.real() + B * p1.imag() + C) / sqrt(A * A + B * B);
}

int n;

void solve()
{
	vector<coord> point, lower, upper, hull;

	for(int i=0; i<n; i++)
	{
		double x, y; cin >> x >> y;
		point.push_back({x, y});
	}
	sort(point.begin(), point.end(), cmp);

	for(int i=0; i<n; i++)
	{
		while(lower.size() >= 2 && CCW(lower[lower.size()-2], lower[lower.size()-1], point[i]) <= 0)
			lower.pop_back();
		lower.push_back(point[i]);
	}
	for(int i=n-1; i>=0; i--)
	{
		while(upper.size() >= 2 && CCW(upper[upper.size()-2], upper[upper.size()-1], point[i]) <= 0)
			upper.pop_back();
		upper.push_back(point[i]);
	}

	lower.pop_back(), upper.pop_back();
	hull = lower;
	for(auto p : upper) hull.push_back(p);

	//반드시 변을 중심으로 답을 구한다. 꼭짓점을 중심으로 거리를 구하면 원하지 않은 최솟값이 나온다.
	double ans = 1e18;
	for(int i=0; i<hull.size(); i++)
	{
		double mx = 0;
		for(int j=0; j<hull.size(); j++)
		{
			mx = max(mx, calDist(hull[j], hull[i], hull[(i+1)%hull.size()]));
		}
		ans = min(ans, mx);
	}

	cout << fixed << setprecision(2) << ceil(ans * 100.0) / 100.0 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cnt = 0;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		cout << "Case " << ++cnt << ": ";
		solve();
	}
}

//long double을 사용하면 복잡하게 소숫점 처리를 해야 하니 double을 사용한다.