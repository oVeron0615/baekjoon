#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
vector<pii> house, chicken;
int N, M; 
vector<int> per;
int ans = INF;

void dist()
{
	int sum = 0;
	for(auto [hx, hy] : house)
	{
		int mnDist = INF;
		for(int c : per)
		{
			auto [cx, cy] = chicken[c];
			mnDist = min(mnDist, abs(hx - cx) + abs(hy - cy));
		}
		sum += mnDist;
	}
	ans = min(ans, sum);
}

void makePer(int n, int m)
{
	if(m == 0) dist();

	for(int i=n; i<chicken.size(); i++)
	{
		per.push_back(i);
		makePer(i+1, m-1);
		per.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			int num; cin >> num;
			if(num == 1) house.push_back({i, j});
			else if(num == 2) chicken.push_back({i, j});
		}
	}

	makePer(0, M);
	cout << ans;
}