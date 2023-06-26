#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int H, W;
int board[21][21];
int ans = 0;

void solve(int x, int y, int val)
{
    if (y > W)
        x++, y = 1;

    while (x <= H)
    {
        if (board[x][y] == 0)
        {
            bool check = false;
            if (x == 1 || y == 1)
                check = true;
            else
            {
                if (board[x - 1][y - 1] == board[x - 1][y] || board[x - 1][y - 1] == board[x][y - 1])
                    check = true;
            }

            if (check)
            {
                board[x][y] = val;

                if (x < H && board[x + 1][y] == 0)
                {
                    board[x + 1][y] = val;
                    solve(x, y + 1, val + 1);
                    board[x + 1][y] = 0;
                }
                if (y < W && board[x][y + 1] == 0)
                {
                    board[x][y + 1] = val;
                    solve(x, y + 2, val + 1);
                    board[x][y + 1] = 0;
                }

                board[x][y] = 0;
            }
            return;
        }

        if (++y > W)
            x++, y = 1;
    }

    if (x > H)
    {
        ans++;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> H >> W;
    while (!(H == 0 && W == 0))
    {
        memset(board, 0, sizeof(board));
        ans = 0;

        solve(1, 1, 1);
        cout << ans << "\n";

        cin >> H >> W;
    }
}