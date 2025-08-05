#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef complex<ld> coord;

coord vec(coord p1, coord p2) { return p2 - p1; };
ld CCW(coord p1, coord p2, coord p3)
{
	coord p12 = vec(p1, p2), p23 = vec(p2, p3);
	return (conj(p12) * p23).imag();
}

bool operator<(const coord& p1, const coord& p2)
{
	if(p1.real() == p2.real()) return p1.imag() < p2.imag();
	return p1.real() < p2.real();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ld x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	coord a = {x1, y1}, b = {x2, y2}, c = {x3, y3}, d = {x4, y4};
	if(b < a) swap(a, b);
	if(d < c) swap(c, d);

	ld abCCW = CCW(a, b, c) * CCW(a, b, d);
	ld cdCCW = CCW(c, d, a) * CCW(c, d, b);

	if(abCCW == 0 && cdCCW == 0) cout << !(b < c || d < a);
	else cout << (abCCW <= 0 && cdCCW <= 0);
}