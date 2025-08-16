#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> coord;

const int MAXN = 2000;
int n;
coord point[MAXN];

bool isCres(coord p1, coord p2)
{
	return p1.real() == p2.real() ? p1.imag() < p2.imag() : p1.real() < p2.real();
};

coord vec(coord p1, coord p2) { return p2 - p1; }

ll CCW(coord p1, coord p2, coord p3)
{
	coord p12 = vec(p2, p1), p23 = vec(p3, p2);
	return (conj(p12) * p23).imag();
}

auto cmp = [](coord p1, coord p2) 
{
	ll ret = CCW(point[0], p1, p2);
	if(ret == 0) return abs(p1 - point[0]) < abs(p2 - point[0]);
	else return ret > 0;
};

void solve()
{
	map<pll, int> idx;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		ll x, y; cin >> x >> y;
		point[i] = {x, y};
		idx[{x, y}] = i;
	}

	for(int i=1; i<n; i++)
		if(isCres(point[i], point[0])) swap(point[i], point[0]);
	sort(point + 1, point + n, cmp);

	int line = n-1;
	for(int i=n-1; i>=1; i--)
	{
		if(CCW(point[0], point[i], point[i-1]) == 0) line--;
		else break;
	}
	reverse(point + line, point + n);

	for(int i=0; i<n; i++) cout << idx[{point[i].real(), point[i].imag()}] << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int c; cin >> c;
	while(c--) solve();
}