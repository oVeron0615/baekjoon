#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1'000'001;
	int A[MAXN];
	int prev[MAXN] = {};

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	vector<pii> lastVal;
	for(int i=1; i<=N; i++)
	{
		auto iter = lower_bound(lastVal.begin(), lastVal.end(), pii{A[i], 0});

		if(iter != lastVal.begin()) prev[i] = (*(iter-1)).second;
		if(iter == lastVal.end()) lastVal.push_back({A[i], i});
		else *iter = {A[i], i};
	}

	vector<int> ans;
	int node = (*(lastVal.end()-1)).second;
	while(node)
	{
		ans.push_back(node);
		node = prev[node];
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for(int a : ans) cout << A[a] << " ";
}