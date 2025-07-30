#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, r, c;

int solve(int n, int x, int y)
{
	if(r == x && c == y) return 0;

	int half = pow(2, n-1);
	int area = half * half;
	if(x <= r && r < x + half)
	{
		if(y <= c && c < y + half) return solve(n-1, x, y);
		else return solve(n-1, x, y + half) + area * 1;
	}
	else
	{
		if(y <= c && c < y + half) return solve(n-1, x + half, y) + area * 2;
		else return solve(n-1, x + half, y + half) + area * 3;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> r >> c;
	cout << solve(N, 0, 0);
}