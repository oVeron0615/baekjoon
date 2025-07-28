#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	int kg3 = 0;
	while(N >= 0 && N % 5) N -= 3, kg3++;

	if(N < 0) cout << -1;
	else cout << kg3 + N / 5;
}