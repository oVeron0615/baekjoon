#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 11;
bool board[MAXN][MAXN];
int N;
vector<pii> bishop;
bool bit = false;
int ans1 = 0, ans2 = 0;

bool isCross(int x, int y)
{
	for(auto [bx, by] : bishop)
	{
		if(abs(x - bx) == abs(y - by)) return true;
	}
	return false;
}

void solve(int xy)
{
	if(xy > N*2) 
	{
		if(bit) ans1 = max(ans1, int(bishop.size()));
		else ans2 = max(ans2, int(bishop.size()));
		return;
	}

	solve(xy + 2);
	for(int x=1; x<xy; x++)
	{
		int y = xy-x;
		if(x > N || y > N || !board[x][y] || isCross(x, y)) continue;

		bishop.push_back({x, y});
		solve(xy + 2);
		bishop.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> board[i][j];
	
	bit = true; solve(2);
	bit = false; solve(3);
	cout << ans1 + ans2;
}