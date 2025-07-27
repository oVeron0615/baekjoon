#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, M, S, E;
vector<pii> graph[10001];
priority_queue<pii> pq;
int dist[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{1}; i <= M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({C, B});
        graph[B].push_back({C, A});
    }
    cin >> S >> E;

    dist[S] = inf;
    pq.push({dist[S], S});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d < dist[u])
            continue;

        for (auto [d, v] : graph[u])
        {
            if (dist[v] < min(dist[u], d))
            {
                dist[v] = min(dist[u], d);
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[E] << "\n";
}