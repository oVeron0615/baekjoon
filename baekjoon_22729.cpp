#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int> tii;

int h, w;
char board[51][51];
tii rect[26];
int cache[26];
bool isSafe;

tii cmp(tii tup, tii ntup)
{
    auto [sx, bx, sy, by] = tup;
    auto [nsx, nbx, nsy, nby] = ntup;
    sx = min(sx, nsx), bx = max(bx, nbx);
    sy = min(sy, nsy), by = max(by, nby);
    tup = {sx, bx, sy, by};
    return tup;
}

void solve2(int idx)
{
    auto [sx, bx, sy, by] = rect[idx];
    cache[idx] = 1;

    for (int i{sx}; i <= bx; i++)
    {
        for (int j{sy}; j <= by; j++)
        {
            if (board[i][j] == '.')
            {
                isSafe = false;
                return;
            }
            else if (board[i][j] != 'A' + idx)
            {
                if (cache[board[i][j] - 'A'] == 0)
                    solve2(board[i][j] - 'A');
                else if (cache[board[i][j] - 'A'] == 1)
                {
                    isSafe = false;
                    return;
                }
            }

            if (!isSafe)
                return;
        }
    }
    cache[idx] = 2;
}

void solve1()
{
    fill(rect, rect + 26, make_tuple(inf, -inf, inf, -inf));
    memset(cache, 0, sizeof(cache));
    isSafe = true;

    cin >> h >> w;
    for (int i{1}; i <= h; i++)
    {
        for (int j{1}; j <= w; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '.')
                continue;
            rect[board[i][j] - 'A'] = cmp(rect[board[i][j] - 'A'], {i, i, j, j});
        }
    }

    for (int i{0}; i < 26; i++)
    {
        if (rect[i] == make_tuple(inf, -inf, inf, -inf) || cache[i] == 2)
            continue;
        solve2(i);

        if (!isSafe)
            break;
    }

    if (isSafe)
        cout << "SAFE\n";
    else
        cout << "SUSPICIOUS\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve1();
}