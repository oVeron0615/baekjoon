#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n; 
int PA = 1;
vector<int> B;

void solve(int cnt, int prev)
{
	if(cnt == n)
	{
		int PB = 1;
		for(int b : B) PB *= b;

		if(PA < PB)
		{
			for(int b : B) cout << b << " ";
			exit(0);
		}
		return;
	}

	for(int i=prev; i<=9; i++)
	{
		B.push_back(i);
		solve(cnt + 1, i);
		B.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=1; i<=n; i++)
	{
		int a; cin >> a;
		PA *= a;
	}

	solve(0, 1);
	cout << -1;
}