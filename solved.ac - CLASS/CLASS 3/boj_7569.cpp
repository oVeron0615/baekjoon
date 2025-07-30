#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct loc
{
	int h, n, m, t;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int M, N, H; cin >> M >> N >> H;
	const int SZ = 101;
	int tomato[SZ][SZ][SZ];
	queue<loc> qu;

	for(int h=1; h<=H; h++)
	{
		for(int n=1; n<=N; n++)
		{
			for(int m=1; m<=M; m++)
			{
				cin >> tomato[h][n][m];
				if(tomato[h][n][m] == 1) qu.push({h, n, m, 0});
			}
		}
	}

	int ans = 0;
	int dir[3][6] = {{-1, 1, 0, 0, 0, 0}, {0, 0, -1, 1, 0, 0}, {0, 0, 0, 0, -1, 1}};
	while(!qu.empty())
	{
		auto [h, n, m, t] = qu.front(); qu.pop();
		ans = t;
		
		for(int i=0; i<6; i++)
		{
			int nxh = h + dir[0][i];
			int nxn = n + dir[1][i];
			int nxm = m + dir[2][i];

			if(1 <= nxh && nxh <= H && 1 <= nxn && nxn <= N && 1 <= nxm && nxm <= M)
			{
				if(tomato[nxh][nxn][nxm] == 0)
				{
					tomato[nxh][nxn][nxm] = 1;
					qu.push({nxh, nxn, nxm, t+1});
				}
			}
		}
	}

	for(int h=1; h<=H; h++)
	{
		for(int n=1; n<=N; n++)
		{
			for(int m=1; m<=M; m++)
			{
				if(tomato[h][n][m] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << ans;
}