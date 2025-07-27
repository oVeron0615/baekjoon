#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
char board[51][51];
int vis[2][51][51]; // vis[0][][] : 위아래
int dist[2][51][51];
int dir[2][5] = {{-1, 0, 1, 0, 0}, {0, -1, 0, 1, 0}};
tiii S, E;
queue<tiii> qu;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{1}; i <= N; i++)
        for (int j{1}; j <= N; j++)
            cin >> board[i][j];

    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= N; j++)
        {
            if (board[i][j] == 'B')
            {
                if (i > 1 && i < N)
                    if (board[i - 1][j] == 'B' && board[i + 1][j] == 'B')
                        S = {0, i, j};
                if (j > 1 && j < N)
                    if (board[i][j - 1] == 'B' && board[i][j + 1] == 'B')
                        S = {1, i, j};
            }
            if (board[i][j] == 'E')
            {
                if (i > 1 && i < N)
                    if (board[i - 1][j] == 'E' && board[i + 1][j] == 'E')
                        E = {0, i, j};
                if (j > 1 && j < N)
                    if (board[i][j - 1] == 'E' && board[i][j + 1] == 'E')
                        E = {1, i, j};
            }
        }
    } // 시작 위치의 중앙, 끝 위치의 중앙 구하기

    memset(dist, -1, sizeof(dist));

    qu.push(S);
    auto [sr, sx, sy] = S;
    dist[sr][sx][sy] = 0;
    while (!qu.empty())
    {
        auto [cr, cx, cy] = qu.front();
        qu.pop();

        auto [er, ex, ey] = E;
        if (er == cr && ex == cx && ey == cy)
            break;

        for (int i{0}; i < 5; i++)
        {
            int nx = cx + dir[0][i];
            int ny = cy + dir[1][i];
            int nr = cr;

            if (i == 4)
            {
                nr = 1 - nr;

                bool isMove = true;
                for (int x{nx - 1}; x <= nx + 1; x++)
                {
                    for (int y{ny - 1}; y <= ny + 1; y++)
                    {
                        if (x < 1 || x > N || y < 1 || y > N)
                            isMove = false;
                        if (board[x][y] == '1')
                            isMove = false;
                    }
                }
                if (!isMove)
                    continue;
            }
            else if ((cr == 0 && i % 2 == 1) || (cr == 1 && i % 2 == 0))
            {
                vector<pii> v;
                v.push_back({nx, ny});
                v.push_back({nx + dir[0][(i - 1 + 4) % 4], ny + dir[1][(i - 1 + 4) % 4]});
                v.push_back({nx + dir[0][(i + 1) % 4], ny + dir[1][(i + 1) % 4]});

                bool isMove = true;
                for (auto [x, y] : v)
                {
                    if (x < 1 || x > N || y < 1 || y > N)
                        isMove = false;
                    if (board[x][y] == '1')
                        isMove = false;
                }
                if (!isMove)
                    continue;
            }
            else
            {
                int x = nx + dir[0][i];
                int y = ny + dir[1][i];
                if (x < 1 || x > N || y < 1 || y > N)
                    continue;
                if (board[x][y] == '1')
                    continue;
            }

            if (dist[nr][nx][ny] != -1)
                continue;

            dist[nr][nx][ny] = dist[cr][cx][cy] + 1;
            qu.push({nr, nx, ny});
        }
    }

    auto [er, ex, ey] = E;
    if (dist[er][ex][ey] == -1)
        cout << "0\n";
    else
        cout << dist[er][ex][ey] << "\n";
}