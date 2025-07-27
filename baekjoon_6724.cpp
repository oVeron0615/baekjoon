#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

pii s, e;
char sDir;
string board[10][10][4];
bool exist[10][10];
int dir[2][4] = {{0, 1, 0, -1}, {-1, 0, 1, 0}};
queue<tii> qu;
bool vis[10][10][4];
tii trace[10][10][4];
int cnt = 0;

void tracing(int x, int y, int d)
{
    if (x == 0 && y == 0)
        return;

    auto [nx, ny, nd] = trace[x][y][d];
    tracing(nx, ny, nd);

    if (cnt == 0)
        cout << " ";
    cout << " (" << x << "," << y << ")";
    if (++cnt == 10)
    {
        cout << "\n";
        cnt = 0;
    }
}

void init()
{
    memset(exist, false, sizeof(exist));
    memset(vis, false, sizeof(vis));
    for (int i{1}; i <= 9; i++)
        for (int j{1}; j <= 9; j++)
            for (int k{0}; k < 4; k++)
                board[i][j][k] = "";
    fill(&trace[0][0][0], &trace[9][10][4], make_tuple(0, 0, 0));
    while (!qu.empty())
        qu.pop();
    cnt = 0;
}

void solve()
{
    init();

    int sx, sy, ex, ey;
    char sd;
    cin >> sx >> sy >> sd >> ex >> ey;
    s = {sx, sy}, sDir = sd, e = {ex, ey};
    exist[sx][sy] = exist[ex][ey] = true;

    int x, y;
    cin >> x;
    while (x != 0)
    {
        cin >> y;
        exist[x][y] = true;

        string cmd;
        cin >> cmd;
        while (cmd != "*")
        {
            switch (cmd[0])
            {
            case 'W':
                board[x][y][0] = cmd.substr(1);
                break;
            case 'S':
                board[x][y][1] = cmd.substr(1);
                break;
            case 'E':
                board[x][y][2] = cmd.substr(1);
                break;
            case 'N':
                board[x][y][3] = cmd.substr(1);
                break;
            }
            cin >> cmd;
        }

        cin >> x;
    }

    int d;
    switch (sDir)
    {
    case 'W':
        d = 0;
        break;
    case 'S':
        d = 1;
        break;
    case 'E':
        d = 2;
        break;
    case 'N':
        d = 3;
        break;
    }
    qu.push({s.first, s.second, d});
    vis[s.first][s.second][d] = true;

    bool check = false;
    while (!qu.empty())
    {
        auto [x, y, d] = qu.front();
        qu.pop();

        int nx, ny;
        nx = x + dir[0][d];
        ny = y + dir[1][d];

        if (!exist[nx][ny])
            continue;

        if (nx == e.first && ny == e.second)
        {
            trace[nx][ny][0] = {x, y, d};
            check = true;
            break;
        }

        for (char c : board[nx][ny][d])
        {
            char nd;
            switch (c)
            {
            case 'F':
                nd = d;
                break;
            case 'L':
                nd = (d + 1) % 4;
                break;
            case 'R':
                nd = (d + 3) % 4;
                break;
            }

            if (vis[nx][ny][nd])
                continue;
            vis[nx][ny][nd] = true;
            qu.push({nx, ny, nd});
            trace[nx][ny][nd] = {x, y, d};
        }
    }

    if (!check)
    {
        cout << "  No solution possible\n";
        return;
    }

    tracing(e.first, e.second, 0);

    if (cnt != 0)
        cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string title;
    cin >> title;
    while (title != "END")
    {
        cout << title << "\n";
        solve();
        cin >> title;
    }
}