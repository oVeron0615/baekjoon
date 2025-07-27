#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int H, W;
char board[501][501];
bool isAdjWall[501][501];
int dist[501][501];
int dir[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
pii S, E;
priority_queue<tii, vector<tii>, greater<tii>> qu;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> H >> W;
    for (int i{1}; i <= H; i++)
    {
        for (int j{1}; j <= W; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
                S = {i, j};
            else if (board[i][j] == 'E')
                E = {i, j};
        }
    }

    for (int i{1}; i <= H; i++)
    {
        for (int j{1}; j <= W; j++)
        {
            bool check = false;
            for (int d{0}; d < 4; d++)
            {
                int nx = i + dir[0][d];
                int ny = j + dir[1][d];

                if (nx >= 1 && nx <= H && ny >= 1 && ny <= W)
                    if (board[nx][ny] == '#')
                        check = true;
            }

            isAdjWall[i][j] = check;
        }
    }

    fill(&dist[0][0], &dist[500][501], INF);

    dist[S.first][S.second] = 0;
    qu.push({0, S.first, S.second});
    while (!qu.empty())
    {
        auto [d, x, y] = qu.top();
        qu.pop();

        if (d > dist[x][y])
            continue;

        for (int i{0}; i < 4; i++)
        {
            int nx = x + dir[0][i];
            int ny = y + dir[1][i];

            if (nx >= 1 && nx <= H && ny >= 1 && ny <= W)
            {
                if (board[nx][ny] == '#')
                    continue;

                if (isAdjWall[x][y] && isAdjWall[nx][ny])
                {
                    if (dist[nx][ny] > dist[x][y])
                    {
                        dist[nx][ny] = dist[x][y];
                        qu.push({dist[nx][ny], nx, ny});
                    }
                }
                else
                {
                    if (dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        qu.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
    }
    cout << dist[E.first][E.second] << "\n";
}