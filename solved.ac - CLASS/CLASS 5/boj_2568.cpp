#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100001;
	pii line[MAXN];
	int prev[MAXN] = {};

	int N; cin >> N;
	for(int i=1; i<=N; i++) 
	{
		int x, y; cin >> x >> y;
		line[i] = {x, y};
	}
	sort(line + 1, line + N + 1);

	vector<pii> lastVal;
	for(int i=1; i<=N; i++)
	{
		auto [x, y] = line[i];
		auto iter = lower_bound(lastVal.begin(), lastVal.end(), pii{y, 0});

		if(iter != lastVal.begin()) prev[i] = (*(iter-1)).second;
		if(iter == lastVal.end()) lastVal.push_back({y, i});
		else *iter = {y, i};
	}

	vector<int> notCut;
	int node = (*(lastVal.end()-1)).second;
	while(node)
	{
		notCut.push_back(node);
		node = prev[node];
	}
	reverse(notCut.begin(), notCut.end());

	cout << N-lastVal.size() << "\n";
	int idx = 0;
	for(int i=1; i<=N; i++)
	{
		if(notCut[idx] == i) idx++;
		else cout << line[i].first << "\n";
	}
}