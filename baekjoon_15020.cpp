#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;
typedef pair<ll, pii> plp;

int h, w;
ll board[501][501];
bool vis[501][501];

int dir[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
priority_queue<plp, vector<plp>, greater<plp>> pq;

int dx, dy;
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> h >> w;
    for (int i{1}; i <= h; i++)
        for (int j{1}; j <= w; j++)
            cin >> board[i][j];
    cin >> dx >> dy;

    pq.push({board[dx][dy], {dx, dy}});
    ans += abs(board[dx][dy]);
    vis[dx][dy] = true;

    while (!pq.empty())
    {
        auto [d, p] = pq.top();
        auto [x, y] = p;
        pq.pop();

        for (int i{0}; i < 8; i++)
        {
            int nx = x + dir[0][i];
            int ny = y + dir[1][i];

            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w)
            {
                if (vis[nx][ny] || board[nx][ny] >= 0)
                    continue;

                if (d < board[nx][ny])
                {
                    pq.push({board[nx][ny], {nx, ny}});
                    ans += abs(board[nx][ny]);
                }
                else
                {
                    pq.push({d, {nx, ny}});
                    ans += abs(d);
                }
                vis[nx][ny] = true;
            }
        }
    }
    cout << ans << "\n";
}