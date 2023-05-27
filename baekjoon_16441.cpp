#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
char board[101][101];
vector<pii> wolf;
bool vis[101][101];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void DFS(int x, int y)
{
    vis[x][y] = true;
    for (int i{0}; i < 4; i++)
    {
        int nx = x, ny = y;
        while (true)
        {
            nx += dir[0][i];
            ny += dir[1][i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
            {
                if (board[nx][ny] == '+')
                    continue;
                else if (board[nx][ny] == '.' && !vis[nx][ny])
                    DFS(nx, ny);
                else if (board[nx][ny] == '#' && !vis[nx - dir[0][i]][ny - dir[1][i]])
                    DFS(nx - dir[0][i], ny - dir[1][i]);
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'W')
            {
                wolf.push_back({i, j});
                board[i][j] = '.';
            }
        }
    }

    for (auto [x, y] : wolf)
        DFS(x, y);

    for (auto [x, y] : wolf)
        board[x][y] = 'W';
    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= M; j++)
        {
            if (board[i][j] == '.' && !vis[i][j])
                cout << 'P';
            else
                cout << board[i][j];
        }
        cout << "\n";
    }
}