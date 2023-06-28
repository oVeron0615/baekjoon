#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

bool board[11][11];
int paper[6] = {0, 5, 5, 5, 5, 5};
int ans = 1e9;

void solve(int x, int y, int cnt)
{
    if (x > 10)
    {
        ans = min(ans, cnt);
        return;
    }

    int nx, ny;
    if (y < 10)
        nx = x, ny = y + 1;
    else
        nx = x + 1, ny = 1;

    if (!board[x][y])
    {
        solve(nx, ny, cnt);
        return;
    }

    for (int p{1}; p <= 5; p++)
    {
        if (x + p - 1 > 10 || y + p - 1 > 10)
            continue;

        if (paper[p])
        {
            bool check = true;
            for (int i{x}; i < x + p; i++)
                for (int j{y}; j < y + p; j++)
                    if (!board[i][j])
                        check = false;

            if (check)
            {
                for (int i{x}; i < x + p; i++)
                    for (int j{y}; j < y + p; j++)
                        board[i][j] = false;
                paper[p]--;

                solve(nx, ny, cnt + 1);

                for (int i{x}; i < x + p; i++)
                    for (int j{y}; j < y + p; j++)
                        board[i][j] = true;
                paper[p]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i{1}; i <= 10; i++)
        for (int j{1}; j <= 10; j++)
            cin >> board[i][j];

    solve(1, 1, 0);
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}