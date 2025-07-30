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
	char board[601][601];
	pii start;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 'I') start = {i, j};
		}
	}

	int ans = 0;
	int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
	bool vis[601][601] = {};
	queue<pii> qu;
	qu.push(start); vis[start.first][start.second] = true;
	while(!qu.empty())
	{
		pii u = qu.front(); qu.pop();
		auto [ux, uy] = u;

		if(board[ux][uy] == 'P') ans++;
		
		for(int i=0; i<4; i++)
		{
			pii v = {ux + dir[0][i], uy + dir[1][i]};
			auto [vx, vy] = v;
			if(vx >= 1 && vx <= N && vy >= 1 && vy <= M)
			{
				if(vis[vx][vy] || board[vx][vy] == 'X') continue;
				vis[vx][vy] = true; qu.push(v);
			}
		}
	}

	if(ans) cout << ans;
	else cout << "TT";
}