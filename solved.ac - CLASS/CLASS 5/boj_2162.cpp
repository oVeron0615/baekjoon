#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef complex<ld> coord;

struct status
{
	coord p1, p2;
};

const int MAXN = 3000;
int par[MAXN], height[MAXN], sz[MAXN];
vector<status> line;
int N;

coord vec(coord p1, coord p2) { return p2 - p1; }

ld CCW(coord p1, coord p2, coord p3)
{
	coord p12 = vec(p1, p2), p23 = vec(p2, p3);
	return (conj(p12) * p23).imag();
}

bool operator<(const coord& p1, const coord& p2)
{
	return p1.real() == p2.real() ? p1.imag() < p2.imag() : p1.real() < p2.real();
}

bool isCross(int i, int j)
{
	auto [p1, p2] = line[i];
	auto [p3, p4] = line[j];

	if(p2 < p1) swap(p1, p2);
	if(p4 < p3) swap(p3, p4);

	ld p12CCW = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	ld p34CCW = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if(p12CCW == 0 && p34CCW == 0) return !(p2 < p3 || p4 < p1);
	else return p12CCW <= 0 && p34CCW <= 0;
}

int Find(int u)
{
	if(par[u] == u) return u;
	return par[u] = Find(par[u]);
}

void Union(int u, int v)
{
	u = Find(u), v = Find(v);
	if(u == v) return;

	if(height[u] < height[v]) swap(u, v);
	par[v] = u;
	if(height[u] == height[v]) height[u]++;
	sz[u] += sz[v];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=0; i<N; i++)
	{
		ld x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		line.push_back({coord(x1, y1), coord(x2, y2)});
	}

	for(int i=0; i<N; i++) par[i] = i, sz[i] = 1;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(isCross(i, j)) Union(i, j);
		}
	}

	int groupCnt = 0;
	int mxSize = 0;
	for(int i=0; i<N; i++)
	{
		if(i == Find(i)) 
		{
			groupCnt++;
			mxSize = max(mxSize, sz[i]);
		}
	}
	cout << groupCnt << "\n" << mxSize;
}