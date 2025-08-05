#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 4'000'001;
	bool isPrime[MAXN];
	fill(&isPrime[0], &isPrime[0] + MAXN, true);
	isPrime[1] = false;

	vector<int> prime;
	for(int i=2; i<MAXN; i++)
	{
		if(!isPrime[i]) continue;
		prime.push_back(i);
		for(int j=i*2; j<MAXN; j+=i)
		{
			isPrime[j] = false;
		}
	}

 	int N; cin >> N;
	int l = 0;
	int sum = 0;
	int ans = 0;
	for(int r=0; r<prime.size(); r++)
	{
		sum += prime[r];
		while(l <= r && sum > N) sum -= prime[l++];
		if(sum == N) ans++;
	}
	cout << ans;
}