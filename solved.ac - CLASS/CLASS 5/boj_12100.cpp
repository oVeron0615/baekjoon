#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 21;
int N;
int ans = 0;
queue<int> nums;

void make2048(int (&board)[][MAXN], int i, int j)
{
	if(nums.empty()) board[i][j] = 0;
	else
	{
		int val = nums.front(); nums.pop();
		if(nums.empty() || val != nums.front()) board[i][j] = val;
		else board[i][j] = val * 2, nums.pop();
	}
}

void solve(int cnt, int (&board)[][MAXN])
{
	if(cnt == 0)
	{
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				ans = max(ans, board[i][j]);
		return;
	}

	int nxboard[MAXN][MAXN];

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
			if(board[i][j]) nums.push(board[i][j]);
		for(int j=1; j<=N; j++) make2048(nxboard, i, j);
	}
	solve(cnt-1, nxboard);

	for(int i=1; i<=N; i++)
	{
		for(int j=N; j>=1; j--)
			if(board[i][j]) nums.push(board[i][j]);
		for(int j=N; j>=1; j--) make2048(nxboard, i, j);
	}
	solve(cnt-1, nxboard);

	for(int j=1; j<=N; j++)
	{
		for(int i=1; i<=N; i++)
			if(board[i][j]) nums.push(board[i][j]);
		for(int i=1; i<=N; i++) make2048(nxboard, i, j);
	}
	solve(cnt-1, nxboard);

	for(int j=1; j<=N; j++)
	{
		for(int i=N; i>=1; i--)
			if(board[i][j]) nums.push(board[i][j]);
		for(int i=N; i>=1; i--) make2048(nxboard, i, j);
	}
	solve(cnt-1, nxboard);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int board[MAXN][MAXN];

	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> board[i][j];

	solve(5, board);
	cout << ans;
}