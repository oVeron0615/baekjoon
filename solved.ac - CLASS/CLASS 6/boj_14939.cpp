#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 10, INF = 1e9;
bool board[SZ][SZ], copyBoard[SZ][SZ];
int dir[2][5] = {{-1, 1, 0, 0, 0}, {0, 0, -1, 1, 0}};

void pushSwitch(int x, int y)
{
	for(int i=0; i<5; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(nx < 0 || nx >= SZ || ny < 0 || ny >= SZ) continue;
		board[nx][ny] ^= true;
	}
}

int turnOff(int i, int cnt)
{
	if(i == SZ)
	{
		for(int i=0; i<SZ; i++)
			for(int j=0; j<SZ; j++)
				if(board[i][j]) return INF;
		return 0;
	}

	for(int j=0; j<SZ; j++)
	{
		if(board[i-1][j]) 
		{
			pushSwitch(i, j);
			cnt++;
		}
	}

	return cnt + turnOff(i + 1, 0);
}

int solve(int bit)
{
	for(int i=0; i<SZ; i++)
		for(int j=0; j<SZ; j++)
			board[i][j] = copyBoard[i][j];

	int cnt = 0;
	for(int i=0; i<SZ; i++)
	{
		if(bit & (1 << i))
		{
			pushSwitch(0, i);
			cnt++;
		}
	}

	return cnt + turnOff(1, 0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for(int i=0; i<SZ; i++)
	{
		for(int j=0; j<SZ; j++)
		{
			char c; cin >> c;
			copyBoard[i][j] = (c == 'O') ? true : false;
		}
	}

	int ans = INF;
	for(int i=0; i<(1 << SZ); i++) 
		ans = min(ans, solve(i));
	
	if(ans == INF) cout << -1;
	else cout << ans;
}