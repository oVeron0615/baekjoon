#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 2001;
	bool dp[MAXN][MAXN];
	int arr[MAXN];

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> arr[i];

	for(int i=0; i<N; i++)
	{
		for(int j=1; j+i<=N; j++)
		{
			if(i < 2) dp[j][j+i] = arr[j] == arr[j+i];
			else dp[j][j+i] = dp[j+1][j+i-1] && arr[j] == arr[j+i];
		}
	}

	int M; cin >> M;
	while(M--)
	{
		int S, E; cin >> S >> E;
		cout << dp[S][E] << "\n";
	}
}