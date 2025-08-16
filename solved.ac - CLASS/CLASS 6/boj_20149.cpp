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

	if(abCCW == 0 && cdCCW == 0)
	{
		if(!(b < c || d < a))
		{
			cout << 1;
			if(CCW(a, b, c) == 0 && CCW(a, b, d) == 0)
			{
				if(b == c) cout << "\n" << b.real() << " " << b.imag();
				else if(d == a) cout << "\n" << a.real() << " " << a.imag();
			}
			else
			{
				if(b == c || b == d) cout << "\n" << b.real() << " " << b.imag();
				else if(a == c || a == d) cout << "\n" << a.real() << " " << a.imag();
			}
		}
		else cout << 0;
	} 
	else
	{
		if(abCCW <= 0 && cdCCW <= 0) //일반형 직선 방정식 2개 연립
		{
			cout << 1 << "\n";
			ld A1 = a.imag() - b.imag(), B1 = b.real() - a.real(), C1 = a.real() * b.imag() - b.real() * a.imag();
			ld A2 = c.imag() - d.imag(), B2 = d.real() - c.real(), C2 = c.real() * d.imag() - d.real() * c.imag();
			cout << fixed << setprecision(10) <<
				(B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1) << " " << (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);
		}
		else cout << 0;
	} 
}