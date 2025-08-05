#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 9;
char board[SZ][SZ];

void solve(int u)
{
	if(u == SZ*SZ)
	{
		for(int i=0; i<SZ; i++)
		{
			for(int j=0; j<SZ; j++)
			{
				cout << board[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}

	int x = u/SZ, y = u%SZ;
	if(board[x][y] != '0') 
	{
		solve(u+1);
		return;
	}
	
	for(int val=1; val<=SZ; val++)
	{
		bool check = true;
		for(int i=0; i<SZ; i++)
			if(board[i][y] - '0' == val) check = false;
		for(int i=0; i<SZ; i++)
			if(board[x][i] - '0' == val) check = false;
		
		int _x = x/3*3, _y = y/3*3;
		for(int i=_x; i<_x+3; i++)
			for(int j=_y; j<_y+3; j++)
				if(board[i][j] - '0' == val) check = false;
		
		if(check)
		{
			board[x][y] = val + '0';
			solve(u+1);
			board[x][y] = '0';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for(int i=0; i<SZ; i++)
		for(int j=0; j<SZ; j++)
			cin >> board[i][j];
	
	solve(0);
}