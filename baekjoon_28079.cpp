#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N;
int B[15];
vector<pii> graph[2][1 << 15];
priority_queue<tii, vector<tii>, greater<tii>> pq;
int dist[2][1 << 15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{0}; i < N; i++)
        cin >> B[i];

    if (N == 1)
    {
        cout << B[0] << "\n";
        return 0;
    }

    for (int S{0}; S < (1 << N); S++)
    {
        for (int i{0}; i < N; i++)
        {
            if (S & (1 << i))
            {
                int _S = S & ~(1 << i);
                graph[1][S].push_back({B[i], _S});
            }
            else
            {
                int _S = S | (1 << i);
                for (int j{i + 1}; j < N; j++)
                {
                    if (_S & (1 << j))
                        continue;
                    if (B[i] != B[j])
                    {
                        int __S = _S | (1 << j);
                        graph[0][S].push_back({max(B[i], B[j]), __S});
                    }
                }
            }
        }
    }

    fill(&dist[0][0], &dist[1][1 << 15], inf);

    dist[0][0] = 0;
    pq.push({dist[0][0], 0, 0});
    while (!pq.empty())
    {
        auto [d, x, u] = pq.top();
        pq.pop();

        if (d > dist[x][u])
            continue;

        for (auto [d, v] : graph[x][u])
        {
            if (dist[1 - x][v] > dist[x][u] + d)
            {
                dist[1 - x][v] = dist[x][u] + d;
                pq.push({dist[1 - x][v], 1 - x, v});
            }
        }
    }

    if (dist[1][(1 << N) - 1] == inf)
        cout << -1 << "\n";
    else
        cout << dist[1][(1 << N) - 1] << "\n";
}