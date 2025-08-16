#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 10;
char board[SZ][SZ];
int dp[SZ][1 << SZ];
int N, M;

bool canCheat(int bit)
{
	for(int b=1; b<M; b++)
		if((bit & (1 << b)) && (bit & (1 << (b-1)))) return true;
	return false;
}

bool cantSit(int i, int bit)
{
	for(int j=0; j<M; j++)
		if(bit & (1 << j) && board[i][j] == 'x') return true;
	return false;
}

int countBit(int bit)
{
	int cnt = 0;
	for(int b=0; b<M; b++)
		if(bit & (1 << b)) cnt++;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int C; cin >> C;
	while(C--) 
	{
		cin >> N >> M;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				cin >> board[i][j];

		memset(dp, 0, sizeof(dp));
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<(1 << M); j++)
			{
				if(i == 0) 
				{
					if(canCheat(j) || cantSit(i, j)) continue;
					dp[i][j] = max(dp[i][j], countBit(j));
					continue;
				}

				for(int k=0; k<(1 << M); k++)
				{
					int bit = j | k;
					if(canCheat(bit) || cantSit(i, j)) continue;
					dp[i][j] = max(dp[i][j], dp[i-1][k] + countBit(j));
				}
			}
		}

		int ans = 0;
		for(int i=0; i<(1 << M); i++) ans = max(ans, dp[N-1][i]);
		cout << ans << "\n";
	}
}