#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
int num[9];
bool vis[9] = {};
vector<int> ans;

void solve(int m)
{
	if(m == 0)
	{
		for(int a : ans) cout << a << " ";
		cout << "\n";
		return;
	}

	int prev = -1;
	for(int i=1; i<=N; i++)
	{
		if(vis[i] || (i > 1 && num[i] == prev)) continue;

		ans.push_back(num[i]); vis[i] = true;
		solve(m-1);
		ans.pop_back(); vis[i] = false;
		prev = num[i];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++) cin >> num[i];
	sort(num + 1, num + N + 1);
	solve(M);
}