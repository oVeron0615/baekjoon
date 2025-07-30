#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 26;
char board[SZ][SZ];
bool vis[SZ][SZ] = {};
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int N;

int DFS(int i, int j)
{
	vis[i][j] = true;
	int ret = 1;
	for(int d=0; d<4; d++)
	{
		int ni = i + dir[0][d];
		int nj = j + dir[1][d];

		if(ni >= 1 && ni <= N && nj >= 1 && nj <= N)
		{
			if(vis[ni][nj] || board[ni][nj] == '0') continue;
			ret += DFS(ni, nj);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> board[i][j];
	
	vector<int> ans;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(vis[i][j] || board[i][j] == '0') continue;
			ans.push_back(DFS(i, j));
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int a : ans) cout << a << "\n";
}