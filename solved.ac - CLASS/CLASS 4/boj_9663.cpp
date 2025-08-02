#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> queen;
int N; 
int ans = 0;

void solve(int x)
{
	if(x == N)
	{
		ans++;
		return;
	}

	for(int y=0; y<N; y++)
	{
		bool check = true;
		for(auto [qx, qy] : queen)
		{
			if(abs(qx - x) == abs(qy - y) || x == qx || y == qy)
				check = false;
		}

		if(check)
		{
			queen.push_back({x, y});
			solve(x+1);
			queen.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	solve(0);
	cout << ans;
}