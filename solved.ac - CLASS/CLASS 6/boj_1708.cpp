#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> coord;

const int MAXN = 100'001;
int N;
vector<coord> point;

auto cmp = [](coord p1, coord p2)
{
	return p1.real() == p2.real() ? p1.imag() < p2.imag() : p1.real() < p2.real();
};

coord vec(coord p1, coord p2) { return p2 - p1; }

ll CCW(coord p1, coord p2, coord p3)
{
	coord p12 = vec(p2, p1), p23 = vec(p3, p2);
	return (conj(p12) * p23).imag();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=0; i<N; i++)
	{
		ll x, y; cin >> x >> y;
		point.push_back({x, y});
	}
	sort(point.begin(), point.end(), cmp); //점들을 x좌표 오름차순, x좌표가 같으면 y좌표 오름차순으로 정렬

	vector<coord> hull1, hull2;
	for(int i=0; i<N; i++) //오른편 볼록 껍질
	{
		//현재 볼록 껍질에서, 상위 2개의 점과 현재 점의 CCW를 구해, 음수가 나오면(껍질이 오목하면) 볼록 껍질 맨 위의 점을 뺀다.
		while(hull1.size() >= 2 && CCW(hull1[hull1.size()-2], hull1[hull1.size()-1], point[i]) <= 0)
			hull1.pop_back();
		hull1.push_back(point[i]);
	}
	for(int i=N-1; i>=0; i--) //왼편 볼록 껍질
	{
		while(hull2.size() >= 2 && CCW(hull2[hull2.size()-2], hull2[hull2.size()-1], point[i]) <= 0)
			hull2.pop_back();
		hull2.push_back(point[i]);
	}

	hull1.pop_back(), hull2.pop_back();

	vector<coord> hull;
	for(coord p : hull1) hull.push_back(p);
	for(coord p : hull2) hull.push_back(p);
	cout << hull.size();
}