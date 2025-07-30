#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int n, m;
int board[1001][1001];
int sx, sy;
bool vis[1001][1001];
queue<tiii> qu;
int dir[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
int ans[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
	    for(int j=1; j<=m; j++)
	    {
	        cin >> board[i][j];
	        if(board[i][j] == 2) sx = i, sy = j;
	    }
	}
	
	qu.push({sx, sy, 0});
	vis[sx][sy] = true;
	while(!qu.empty())
	{
	    auto [x, y, d] = qu.front(); qu.pop();
	    ans[x][y] = d; 
	    
	    for(int i=0; i<4; i++)
	    {
	        int nx = x + dir[0][i];
	        int ny = y + dir[1][i];
	        
	        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
	        {
	            if(!vis[nx][ny] && board[nx][ny] != 0)
	            {
	                qu.push({nx, ny, d+1});
	                vis[nx][ny] = true;
	            }
	        }
	    }
	}
	
	for(int i=1; i<=n; i++)
	{
	    for(int j=1; j<=m; j++)
	    {
	        if(board[i][j] == 0) cout << 0 << " ";
	        else if(board[i][j] == 1 && ans[i][j] == 0) cout << -1 << " ";
	        else cout << ans[i][j] << " ";
	    }
	    cout << "\n";
	}
}