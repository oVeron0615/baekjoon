#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<pll, ll> dp;

ll solve(ll num)
{
	ll res = 0;
	int upperbit_cnt = 0;
	for(int i=60; i>=0; i--)
	{
		if(num & (1LL << i))
		{	
			res += upperbit_cnt * (1LL << i);
			res += (1LL << i) / 2 * i;
			num -= (1LL << i);
			upperbit_cnt++;
		}
	}
	res += upperbit_cnt;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll A, B; cin >> A >> B;
	cout << solve(B) - solve(A-1);
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<pll, ll> dp;

ll solve(ll A, ll B)
{
	if(A == 0 && B == 0) return 0;
	if(dp[{A, B}] != 0) return dp[{A, B}];

	int p = 0;
	while(pow(2, p+1) <= B) p++;

	ll C = pow(2, p);
	if(C <= A) return dp[{A, B}] = solve(A-C, B-C) + (B - A + 1);
	else return dp[{A, B}] = solve(A, C-1) + solve(0, B-C) + (B - C + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll A, B; cin >> A >> B;
	cout << solve(A, B);
}
*/