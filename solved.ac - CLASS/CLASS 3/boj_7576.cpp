#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct loc
{
	int n, m, t;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int M, N; cin >> M >> N;
	const int SZ = 1001;
	int tomato[SZ][SZ];
	queue<loc> qu;

	for(int n=1; n<=N; n++)
	{
		for(int m=1; m<=M; m++)
		{
			cin >> tomato[n][m];
			if(tomato[n][m] == 1) qu.push({n, m, 0});
		}
	}

	int ans = 0;
	int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
	while(!qu.empty())
	{
		auto [n, m, t] = qu.front(); qu.pop();
		ans = t;
		
		for(int i=0; i<4; i++)
		{
			int nxn = n + dir[0][i];
			int nxm = m + dir[1][i];

			if(1 <= nxn && nxn <= N && 1 <= nxm && nxm <= M)
			{
				if(tomato[nxn][nxm] == 0)
				{
					tomato[nxn][nxm] = 1;
					qu.push({nxn, nxm, t+1});
				}
			}
		}
	}

	for(int n=1; n<=N; n++)
	{
		for(int m=1; m<=M; m++)
		{
			if(tomato[n][m] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
}