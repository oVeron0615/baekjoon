#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

bool isPrime(int num)
{
	if(num == 1) return false;
	for(int i=2; i*i<=num; i++)
		if(num % i == 0) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		int num; cin >> num;
		if(isPrime(num)) ans++;
	}
	cout << ans;
}