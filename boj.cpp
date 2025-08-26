#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> coord;

const int SZ = 101;
int n, m;
vector<coord> black, white;

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

void convex_hull(vector<coord>& v)
{
	sort(v.begin(), v.end(), cmp);
	vector<coord> lower, upper;

	for(int i=0; i<v.size(); i++)
	{
		while(lower.size() >= 2 && CCW(lower[lower.size()-2], lower[lower.size()-1], v[i]) <= 0)
			lower.pop_back();
		lower.push_back(v[i]);
	}
	for(int i=v.size()-1; i>=0; i--)
	{
		while(upper.size() >= 2 && CCW(upper[upper.size()-2], upper[upper.size()-1], v[i]) <= 0)
			upper.pop_back();
		upper.push_back(v[i]);
	}
	lower.pop_back(); upper.pop_back();

	v.clear();
	for(coord p : lower) v.push_back(p);
	for(coord p : upper) v.push_back(p);
}

bool isInside(coord p, vector<coord>& v) //다각형 내부 점 판정
{
	int crossCnt = 0;
	for(int i=0; i<v.size(); i++)
	{
		coord p1 = v[i], p2 = v[(i+1)%v.size()];
		if(p.imag() < p1.imag() != p.imag() < p2.imag()) //해당 점을 x축과 오른쪽으로 평행하게 그었을 때 선분과 만나는지 여부
		{
			//직선의 방정식을 사용해 x좌표 교점 구하기
			double A = p1.imag() - p2.imag(), B = p2.real() - p1.real(), C = p1.real() * p2.imag() - p2.real() * p1.imag();
			double crossX = (-B * p.imag() - C) / A;
			if(crossX > p.real()) crossCnt++;
		}
	}

	return crossCnt % 2; //만나는 횟수가 홀수면 내부에 존재
}

bool operator<(const coord& p1, const coord& p2)
{
	if(p1.real() == p2.real()) return p1.imag() < p2.imag();
	return p1.real() < p2.real();
};

bool isCross(coord a, coord b, coord c, coord d)
{
	if(b < a) swap(a, b);
	if(d < c) swap(c, d);

	double abCCW = CCW(a, b, c) * CCW(a, b, d);
	double cdCCW = CCW(c, d, a) * CCW(c, d, b);

	if(abCCW == 0 && cdCCW == 0) return !(b < c || d < a);
	else return abCCW <= 0 && cdCCW <= 0;
}

bool check(vector<coord>& v1, vector<coord>& v2)
{
	for(int i=0; i<v1.size(); i++)
	{
		for(int j=0; j<v2.size(); j++)
		{
			if(isCross(v1[i], v1[(i+1)%v1.size()], v2[j], v2[(j+1)%v2.size()]))
				return false;
		}
	}

	for(coord p : v1)
		if(isInside(p, v2)) return false;
	for(coord p : v2)
		if(isInside(p, v1)) return false;

	return true;
}

void solve()
{
	black.clear(), white.clear();

	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		double x, y; cin >> x >> y;
		black.push_back({x, y});
	}
	for(int i=1; i<=m; i++)
	{
		double x, y; cin >> x >> y;
		white.push_back({x, y});
	}

	if(n >= 3) convex_hull(black);
	if(m >= 3) convex_hull(white);
	
	if(check(black, white)) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}