#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
vector<pii> meeting;

auto cmp = [](pii m1, pii m2)
{
	auto [s1, e1] = m1;
	auto [s2, e2] = m2;

	if (e1 < e2 || (e1 == e2 && s1 < s2))
		return true;
	else
		return false;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i{1}; i <= N; i++)
	{
		int s, e;
		cin >> s >> e;
		meeting.push_back({s, e});
	}
	sort(meeting.begin(), meeting.end(), cmp);

	int ans{0};
	int endTime{0};
	for (auto [s, e] : meeting)
	{
		if (endTime <= s)
		{
			ans++;
			endTime = e;
		}
	}
	cout << ans << "\n";
}