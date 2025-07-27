#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int> tii;

bool board[7][7];
bool vis[7][7];
int dir[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};

void solve()
{
    memset(vis, false, sizeof(vis));

    for (int i{1}; i <= 6; i++)
        for (int j{1}; j <= 6; j++)
            cin >> board[i][j];

    int cnt = 0;
    for (int i{1}; i <= 6; i++)
    {
        for (int j{1}; j <= 6; j++)
        {
            if (vis[i][j])
                continue;

            bool check = false;
            if (board[i][j])
            {
                for (int d{0}; d < 4; d++)
                {
                    int nd, ni, nj, c;

                    nd = (d + 1) % 4;
                    ni = i + dir[0][d];
                    nj = j + dir[1][d];
                    c = 0;
                    while (board[ni][nj] && c < 4)
                    {
                        int nni = ni + dir[0][d];
                        int nnj = nj + dir[1][d];

                        if (board[nni][nnj] && !vis[nni][nnj])
                        {
                            cnt++;
                            vis[i][j] = vis[nni][nnj] = true;
                            check = true;
                            break;
                        }
                        ni += dir[0][nd];
                        nj += dir[1][nd];
                        c++;
                    }
                    if (check)
                        break;

                    nd = (d + 3) % 4;
                    ni = i + dir[0][d];
                    nj = j + dir[1][d];
                    c = 0;
                    while (board[ni][nj] && c < 4)
                    {
                        int nni = ni + dir[0][d];
                        int nnj = nj + dir[1][d];

                        if (board[nni][nnj] && !vis[nni][nnj])
                        {
                            cnt++;
                            vis[i][j] = vis[nni][nnj] = true;
                            check = true;
                            break;
                        }
                        ni += dir[0][nd];
                        nj += dir[1][nd];
                        c++;
                    }
                    if (check)
                        break;
                }
            }
        }
    }

    if (cnt == 3)
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i{1}; i <= 3; i++)
        solve();
}