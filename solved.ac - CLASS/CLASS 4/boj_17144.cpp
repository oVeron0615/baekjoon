#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;
int board[MAXN][MAXN];
int R, C, T;
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
vector<pii> cleaner;

void dust()
{
	int nxBoard[MAXN][MAXN] = {};
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			if(board[i][j] == -1)
			{
				nxBoard[i][j] = board[i][j];
				continue;
			}

			int cnt = 0;
			for(int d=0; d<4; d++)
			{
				int nj = j + dir[1][d];
				int ni = i + dir[0][d];

				if(1 <= ni && ni <= R && 1 <= nj && nj <= C)
				{
					if(board[ni][nj] == -1) continue;
					nxBoard[ni][nj] += board[i][j] / 5;
					cnt++;
				}
			}
			nxBoard[i][j] += board[i][j] - board[i][j] / 5 * cnt;
		}
	}

	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			board[i][j] = nxBoard[i][j];
		}
	}
}

void clean1(pii xy)
{
	auto [x, y] = xy;
	for(int i=x-1; i>1; i--) board[i][1] = board[i-1][1];
	for(int j=1; j<C; j++) board[1][j] = board[1][j+1];
	for(int i=1; i<x; i++) board[i][C] = board[i+1][C];
	for(int j=C; j>2; j--) board[x][j] = board[x][j-1];
	board[x][y+1] = 0;
}

void clean2(pii xy)
{
	auto [x, y] = xy;
	for(int i=x+1; i<R; i++) board[i][1] = board[i+1][1];
	for(int j=1; j<C; j++) board[R][j] = board[R][j+1];
	for(int i=R; i>x; i--) board[i][C] = board[i-1][C];
	for(int j=C; j>2; j--) board[x][j] = board[x][j-1];
	board[x][y+1] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> R >> C >> T;
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == -1) cleaner.push_back({i, j});
		}
	}

	while(T--)
	{
		dust();
		clean1(cleaner[0]);
		clean2(cleaner[1]);
	}

	int ans = 0;
	for(int i=1; i<=R; i++)
	{
		for(int j=1; j<=C; j++)
		{
			if(board[i][j] == -1) continue;
			ans += board[i][j];
		}
	}
	cout << ans;
}