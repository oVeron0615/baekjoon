#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

auto cmp = [](pii p1, pii p2)
{
	if(p1.second == p2.second) return p1.first < p2.first;
	else return p1.second < p2.second;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<pii> meetings;
	for(int i=1; i<=N; i++)
	{
		int s, e; cin >> s >> e;
		meetings.push_back({s, e});
	}

	sort(meetings.begin(), meetings.end(), cmp);

	int ans = 0;
	int endTime = 0;
	for(auto [s, e] : meetings)
	{
		if(endTime <= s) endTime = e, ans++;
	}
	cout << ans;
}