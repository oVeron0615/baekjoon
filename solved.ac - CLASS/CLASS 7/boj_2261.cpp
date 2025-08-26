#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, INF = 1e9;
pii point[MAXN];
int n;

int dist(pii p1, pii p2) 
{ 
	return (p1.first - p2.first) * (p1.first - p2.first) 
		+ (p1.second - p2.second) * (p1.second - p2.second); 
}

int solve(int s, int e) //분할 정복
{
	if(s == e) return INF;

	int m = (s+e)/2; //두 구간을 가르는 기준선
	int res = min(solve(s, m), solve(m+1, e)); //왼쪽 구간과 오른쪽 구간에서 구한 거리의 최솟값 중 짧은 것 선택

	vector<pii> strip;
	for(int i=s; i<=e; i++) //기준선으로부터 거리가 sqrt(res) = d 이하로 떨어진 것들만 후보군이 될 수 있다.
	{
		if((point[i].first - point[m].first) * (point[i].first - point[m].first) <= res)
			strip.push_back(point[i]);
	}
	sort(strip.begin(), strip.end(), [](pii p1, pii p2){ return p1.second < p2.second; }); //y좌표 기준 정렬

	//y좌표 오름차순으로, 거리가 d보다 적게 떨어진 점들을 구해본다.
	//이때 두 구간의 점들은 거리가 d보다 멀리 떨어져 있고, 후보군에 든 점들은 기준선으로부터 좌우로 d 이하로 떨어진 점들이다.
	//현재 점이 관심 있는 구간은 세로가 d, 가로가 2d인 직사각형 내부에 든 점들이다. 해당 직사각형 외부에 있는 점들은 거리가 d보다 길다.
	//이 직사각형에 들어갈 수 있는 점은, 비둘기집 원리에 의해 현재 점을 포함하여 최대 8개 뿐이다.
	//따라서 7개의 점만 살펴보면 답을 구할 수 있다.
	for(int i=0; i<strip.size(); i++)
		for(int j=i+1; j<min(i+8, int(strip.size())); j++)
			res = min(res, dist(strip[i], strip[j]));
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=1; i<=n; i++)
	{
		int x, y; cin >> x >> y;
		point[i] = {x, y};
	}
	sort(point + 1, point + n + 1);

	cout << solve(1, n);
}