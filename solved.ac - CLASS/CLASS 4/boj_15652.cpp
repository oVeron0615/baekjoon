#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M; 
vector<int> ans;

void solve(int n, int m)
{
	if(m == 0)
	{
		for(int a : ans) cout << a << " ";
		cout << "\n";
		return;
	}

	for(int i=n; i<=N; i++)
	{
		ans.push_back(i);
		solve(i, m-1);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	solve(1, M);
}