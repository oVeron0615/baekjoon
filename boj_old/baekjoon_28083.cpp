#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
int h[1001][1001];
ll c[1001][1001];

map<int, vector<pii>> sortByH;
bool vis[1001][1001];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

pii par[1001][1001];
int height[1001][1001];
ll ans[1001][1001];

pii Find(int x, int y)
{
    if (par[x][y] == pair{-1, -1})
        return {x, y};
    return par[x][y] = Find(par[x][y].F, par[x][y].S);
}

void Union(pii p1, pii p2)
{
    p1 = Find(p1.F, p1.S);
    p2 = Find(p2.F, p2.S);

    if (p1 == p2)
        return;

    if (height[p1.F][p1.S] < height[p2.F][p2.S])
        swap(p1, p2);
    par[p2.F][p2.S] = p1;

    if (height[p1.F][p1.S] == height[p2.F][p2.S])
        height[p1.F][p1.S]++;

    c[p1.F][p1.S] += c[p2.F][p2.S];
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
            cin >> h[i][j];
            sortByH.insert({h[i][j], vector<pii>()});
            sortByH[h[i][j]].push_back({i, j});
        }
    }
    for (int i{1}; i <= N; i++)
        for (int j{1}; j <= M; j++)
            cin >> c[i][j];

    fill(&par[0][0], &par[1000][1001], pair{-1, -1});

    for (auto iter = sortByH.begin(); iter != sortByH.end(); iter++)
    {
        auto [H, coordV] = *iter;

        for (auto [x, y] : coordV)
        {
            vis[x][y] = true;
            for (int i{0}; i < 4; i++)
            {
                int nx = x + dir[0][i];
                int ny = y + dir[1][i];

                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
                {
                    if (h[nx][ny] > h[x][y])
                        continue;
                    Union({x, y}, {nx, ny});
                }
            }
        }

        for (auto [x, y] : coordV)
        {
            auto [px, py] = Find(x, y);
            ans[x][y] = c[px][py];
        }
    }

    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= M; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}