#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int M, N; cin >> M >> N;
	vector<bool> isSieved(N+1);
	isSieved[1] = true;
	for(int i=2; i<=N; i++)
	{
		if(isSieved[i]) continue;
		for(int j=i*2; j<=N; j+=i) isSieved[j] = true;
	}

	for(int i=M; i<=N; i++)
		if(!isSieved[i]) cout << i << "\n";
}