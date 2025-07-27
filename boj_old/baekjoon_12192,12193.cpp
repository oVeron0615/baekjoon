#include <bits/stdc++.h>
#define AR 1000
#define INF 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
int W[101];
vector<pii> graph[101000];
priority_queue<tii, vector<tii>, greater<tii>> pq;
int dist[101000][2]; // 정점, 지하철 탑승 여부
int S, E;

void query()
{
    fill(&dist[0][0], &dist[100999][2], INF);

    dist[S][0] = 0;
    pq.push({dist[S][0], S, 0});
    while (!pq.empty())
    {
        auto [d, u, pos] = pq.top();
        pq.pop();

        if (d > dist[u][pos])
            continue;

        for (auto [d, v] : graph[u])
        {
            if (u / AR == v / AR)
            {
                if (pos)
                {
                    if (dist[v][pos] > dist[u][pos] + d)
                    {
                        dist[v][pos] = dist[u][pos] + d;
                        pq.push({dist[v][pos], v, pos});
                    }
                }
                else
                {
                    if (dist[v][!pos] > dist[u][pos] + d + W[u / AR])
                    {
                        dist[v][!pos] = dist[u][pos] + d + W[u / AR];
                        pq.push({dist[v][!pos], v, !pos});
                    }
                }
            }
            else
            {
                if (dist[v][0] > dist[u][pos] + d)
                {
                    dist[v][0] = dist[u][pos] + d;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
    }

    if (dist[E][0] == INF && dist[E][1] == INF)
        cout << -1 << "\n";
    else
        cout << min(dist[E][0], dist[E][1]) << "\n";
}

void solve()
{
    fill(&graph[0], &graph[101000], vector<pii>());

    cin >> N;
    for (int i{1}; i <= N; i++)
    {
        int SN;
        cin >> SN;
        cin >> W[i];

        for (int j{1}; j < SN; j++)
        {
            int Time;
            cin >> Time;

            int u = i * AR + j - 1;
            int v = u + 1;
            graph[u].push_back({Time, v});
            graph[v].push_back({Time, u});
        }
    }

    cin >> M;
    for (int i{1}; i <= M; i++)
    {
        int m1, s1, m2, s2, t;
        cin >> m1 >> s1 >> m2 >> s2 >> t;

        int u = m1 * AR + s1 - 1;
        int v = m2 * AR + s2 - 1;
        graph[u].push_back({t, v});
        graph[v].push_back({t, u});
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        S = x1 * AR + y1 - 1;
        E = x2 * AR + y2 - 1;

        query();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int i{1}; i <= T; i++)
    {
        cout << "Case #" << i << ":\n";
        solve();
    }
}