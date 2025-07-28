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
	char board[50][50];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> board[i][j];
	
	int ans = 2500;
	for(int i=0; i<=N-8; i++)
	{
		for(int j=0; j<=M-8; j++)
		{
			int B0 = 0, W0 = 0, B1 = 0, W1 = 0;
			for(int n=0; n<8; n++)
			{
				for(int m=0; m<8; m++)
				{
					if((n + m) % 2 == 0)
					{
						if(board[i + n][j + m] == 'B') B0++;
						else W0++;
					}
					else
					{
						if(board[i + n][j + m] == 'B') B1++;
						else W1++;
					}
				}
			}

			ans = min(ans, min(B0 + W1, W0 + B1));
		}
	}

	cout << ans;
}