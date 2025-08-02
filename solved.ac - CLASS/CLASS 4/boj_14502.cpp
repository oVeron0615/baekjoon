#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 8;
int lab[SZ][SZ];
int safeZone;
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
bool vis[SZ][SZ];
int N, M; 

void DFS(int x, int y)
{
	vis[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];

		if(0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if(vis[nx][ny] || lab[nx][ny]) continue;
			DFS(nx, ny);
			safeZone--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> virus;
	int cnt0 = 0;

	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> lab[i][j];
			if(lab[i][j] == 2) virus.push_back(i*M+j);
			if(lab[i][j] == 0) cnt0++;
		}
	}

	int ans = 0;
	for(int i=0; i<N*M; i++)
	{
		for(int j=i+1; j<N*M; j++)
		{
			for(int k=j+1; k<N*M; k++)
			{
				if(lab[i/M][i%M] || lab[j/M][j%M] || lab[k/M][k%M]) continue;
				lab[i/M][i%M] = lab[j/M][j%M] = lab[k/M][k%M] = 1;
				
				fill(&vis[0][0], &vis[0][0] + SZ * SZ, false);
				safeZone = cnt0 - 3;
				for(int v : virus) DFS(v/M, v%M);
				ans = max(ans, safeZone);

				lab[i/M][i%M] = lab[j/M][j%M] = lab[k/M][k%M] = 0;
			}
		}
	}
	cout << ans;
}