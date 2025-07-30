#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> psum(N+1, 0);
	for(int i=1; i<=N; i++)
	{
		int num; cin >> num;
		psum[i] = psum[i-1] + num;
	}

	while(M--)
	{
		int i, j; cin >> i >> j;
		cout << psum[j] - psum[i-1] << "\n";
	}
}