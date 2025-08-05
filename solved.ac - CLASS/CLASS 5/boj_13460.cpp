#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 11, INF = 1e9;
char board[SZ][SZ];
int N, M;
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int ans = INF;

pii moveBead(pii bead, pii otherbead, int d)
{
	auto [x, y] = bead;
	while(true)
	{
		int nx = x + dir[0][d];
		int ny = y + dir[1][d];

		if(board[nx][ny] == 'O') return {-1, -1};
		else if(board[nx][ny] == '#') return {x, y};
		else
		{
			if(pii{nx, ny} == otherbead) return {x, y};
			x = nx, y = ny;
		}
	}
}

bool redIsFront(pii red, pii blue, int d)
{
	if(d == 0) return red.first < blue.first;
	if(d == 1) return red.first > blue.first;
	if(d == 2) return red.second < blue.second;
	else return red.second > blue.second;
}

void solve(int cnt, pii red, pii blue)
{
	if(cnt > 10) return;

	for(int d=0; d<4; d++)
	{
		bool redIsIn = false, blueIsIn = false;
		pii nxRed, nxBlue;

		if(redIsFront(red, blue, d))
		{
			nxRed = moveBead(red, blue, d);
			if(nxRed == pii{-1, -1}) redIsIn = true;
			nxBlue = moveBead(blue, nxRed, d);
			if(nxBlue == pii{-1, -1}) blueIsIn = true;
		}
		else
		{
			nxBlue = moveBead(blue, red, d);
			if(nxBlue == pii{-1, -1}) blueIsIn = true;
			nxRed = moveBead(red, nxBlue, d);
			if(nxRed == pii{-1, -1}) redIsIn = true;
		}

		if(blueIsIn) continue;
		else if(redIsIn) 
		{
			ans = min(ans, cnt);
			continue;
		}

		solve(cnt + 1, nxRed, nxBlue);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	pii red, blue;

	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 'R') red = {i, j}, board[i][j] = '.';
			if(board[i][j] == 'B') blue = {i, j}, board[i][j] = '.';
		}
	}

	solve(1, red, blue);
	if(ans == INF) cout << -1;
	else cout << ans;
}