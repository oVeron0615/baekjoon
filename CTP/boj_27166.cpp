#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll SZ = 100'001;
ll A, B, X, Y, Z;
ll MC[SZ], turn[SZ];

ll retCeil(ll x, ll a, ll b)
{
	return (x - a + b - 1) / b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> A >> B >> X >> Y >> Z;

	MC[B] = A, turn[B] = 0;
	ll ans = max(Z, retCeil(Z*Y, MC[B], B));

	for(ll i=B+1; i<=Y; i++)
	{
		ll t = max(1LL, retCeil(X, MC[i-1], i-1));

		turn[i] = turn[i-1] + t;
		MC[i] = MC[i-1] + t * (i-1) - X;

		ans = min(ans, max(Z, turn[i] + retCeil(Z*Y, MC[i], i)));
	}
	cout << ans;
}

/*
1. 메가크레딧 생산량의 최댓값은 Y를 넘을 수 없다. 따라서 메가크레딧 생산량의 최댓값을 B에서 Y까지 전부 살펴보면 선형 시간에 답을 구할 수 있다.
2. 만들고자 하는 메가크레딧 생산량의 최댓값을 B'이라 하면, 생산량을 B'까지 최대한 빠르게 만들어야 최소 턴 수를 구할 수 있다.
3. 우리가 필요한 메가크레딧은 Y*Z이다. 따라서 생산량을 B'까지 만들었을 때의 턴 수에, 이때 남은 메가크레딧에서 Y*Z만큼 메가크레딧을 만들 때까지의 턴 수를 더하면 답을 구할 수 있다. 
턴 수를 구할 때 ceil 함수의 정수 버전을 구현할 필요가 있으며, 턴 수가 Z보다 작을 수 없음에 유의해야 한다. 
*/