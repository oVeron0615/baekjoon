#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K; cin >> N >> K;
	vector<int> coins(N);
	for(int& coin : coins) cin >> coin;

	int ans = 0;
	int coinsIdx = N-1;
	while(K)
	{
		if(K >= coins[coinsIdx])
		{
			ans += K / coins[coinsIdx];
			K %= coins[coinsIdx];
		}
		coinsIdx--;
	}
	cout << ans;
}

//동전이 배수 관계에 있기 때문에 값이 큰 동전부터 많이 사용하는 그리디 알고리즘을 적용한다.