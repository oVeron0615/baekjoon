#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int factorial(int n)
{
	if(n == 0) return 1;
	else
	{
		int ret = 1;
		for(int i=1; i<=n; i++) ret *= i;
		return ret;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K; cin >> N >> K;
	cout << factorial(N) / (factorial(K) * factorial(N - K));
}