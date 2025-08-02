#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 6144;
char board[MAXN][MAXN];

void solve(int x, int y, int N)
{
	if(N == 3)
	{
		board[x][y] = board[x+1][y-1] = board[x+1][y+1] = '*';
		for(int i=y-2; i<=y+2; i++) board[x+2][i] = '*';
		return;
	}

	solve(x + N/2, y - N/2, N/2);
	solve(x, y, N/2);
	solve(x + N/2, y + N/2, N/2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	fill(&board[0][0], &board[0][0] + MAXN * MAXN, ' ');
	solve(0, N-1, N);

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N*2; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}