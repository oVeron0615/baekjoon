#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, M, T;
int castle[101][101];
int dist[101][101];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, 1, -1}};
queue<pii> qu;
pii gramr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> T;
    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= M; j++)
        {
            cin >> castle[i][j];
            if (castle[i][j] == 2)
                gramr = {i, j};
        }
    }

    fill(&dist[0][0], &dist[N][M + 1], inf);

    qu.push({1, 1});
    dist[1][1] = 0;
    while (!qu.empty())
    {
        auto [cx, cy] = qu.front();
        qu.pop();

        for (int i{0}; i < 4; i++)
        {
            int nx = cx + dir[0][i];
            int ny = cy + dir[1][i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
            {
                if (dist[nx][ny] != inf || castle[nx][ny] == 1)
                    continue;

                qu.push({nx, ny});
                dist[nx][ny] = dist[cx][cy] + 1;
            }
        }
    }

    auto [gx, gy] = gramr;
    int gramrDist = (N - gx) + (M - gy);
    int ans = min(gramrDist + dist[gx][gy], dist[N][M]);

    if (ans > T)
        cout << "Fail\n";
    else
        cout << ans << "\n";
}