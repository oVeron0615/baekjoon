#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct status
{
	int r, c, s, d, z;
};

const int SZ = 101;
int R, C, M;
status shark[SZ * SZ];

void sharkMove(int (&nxBoard)[][SZ], int sharkIdx)
{
	auto& [r, c, s, d, z] = shark[sharkIdx];

	int dist;
	if(d == 1)
	{
		dist = s % ((R-1)*2);
		if(dist <= r - 1) r -= dist;
		else if(dist <= r + R - 2) r = 1 + (dist - (r - 1)), d = 2;
		else r = R - (dist - (r + R - 2));
	}
	else if(d == 2)
	{
		dist = s % ((R-1)*2);
		if(dist <= R - r) r += dist;
		else if(dist <= 2 * R - r - 1) r = R - (dist - (R - r)), d = 1;
		else r = 1 + (dist - (2 * R - r - 1));
	}
	else if(d == 3)
	{
		dist = s % ((C-1)*2);
		if(dist <= C - c) c += dist;
		else if(dist <= 2 * C - c - 1) c = C - (dist - (C - c)), d = 4;
		else c = 1 + (dist - (2 * C - c - 1));
	}
	else
	{
		dist = s % ((C-1)*2);
		if(dist <= c - 1) c -= dist;
		else if(dist <= c + C - 2) c = 1 + (dist - (c - 1)), d = 3;
		else c = C - (dist - (c + C - 2));
	}

	if(nxBoard[r][c])
	{
		if(shark[nxBoard[r][c]].z < z) nxBoard[r][c] = sharkIdx;
	}
	else nxBoard[r][c] = sharkIdx;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int board[SZ][SZ] = {};

	cin >> R >> C >> M;
	for(int i=1; i<=M; i++)
	{
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
		shark[i] = {r, c, s, d, z};
		board[r][c] = i;
	}

	int ans = 0;
	for(int j=1; j<=C; j++)
	{
		for(int i=1; i<=R; i++)
		{
			if(board[i][j]) 
			{
				ans += shark[board[i][j]].z;
				board[i][j] = 0;
				break;
			}
		}

		int nxBoard[SZ][SZ] = {};
		for(int r=1; r<=R; r++)
		{
			for(int c=1; c<=C; c++)
			{
				if(board[r][c]) sharkMove(nxBoard, board[r][c]);
			}
		}

		for(int r=1; r<=R; r++)
		{
			for(int c=1; c<=C; c++)
			{
				board[r][c] = nxBoard[r][c];
			}
		}
	}
	cout << ans;
}