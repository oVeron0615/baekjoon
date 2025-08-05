#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 101;
char board[SZ][SZ];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int h, w;
queue<pii> qu;
vector<pii> door[26];
bool vis[SZ][SZ];
int ans = 0;

void openDoor(char k)
{
	for(auto [x, y] : door[k - 'a']) board[x][y] = '.';
}

void task(int x, int y)
{
	if(x < 1 || x > h || y < 1 || y > w) return;
	if(vis[x][y] || board[x][y] == '*' || ('A' <= board[x][y] && board[x][y] <= 'Z')) return;
	
	if('a' <= board[x][y] && board[x][y] <= 'z')
	{
		openDoor(board[x][y]);
		board[x][y] = '.';

		memset(vis, false, sizeof(vis));
		while(!qu.empty()) qu.pop();
		for(int i=1; i<=h; i++)
		{
			for(int j=1; j<=w; j++)
			{
				if(i == 1 || i == h || j == 1 || j == w)
					if(board[i][j] == '.') qu.push({i, j});
			}
		}
	}
	else
	{
		if(board[x][y] == '$') ans++, board[x][y] = '.';
		qu.push({x, y}), vis[x][y] = true;
	}
}

void solve()
{
	memset(vis, false, sizeof(vis));
	fill(&door[0], &door[0] + 26, vector<pii>());
	ans = 0;

	cin >> h >> w;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			cin >> board[i][j];
			if('A' <= board[i][j] && board[i][j] <= 'Z') 
				door[board[i][j] - 'A'].push_back({i, j});
		}
	}

	string key; cin >> key;
	for(char k : key) openDoor(k);

	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(i == 1 || i == h || j == 1 || j == w)
				task(i, j);
		}
	}

	while(!qu.empty())
	{
		auto [x, y] = qu.front(); qu.pop();
		for(int i=0; i<4; i++)
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];

			task(nx, ny);
		}
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}