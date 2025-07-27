#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, M;
vector<int> graph[2000];
bool vis[2000];

void DFS(int u, int d)
{
    if (d == 5)
    {
        cout << "1\n";
        exit(0);
    }

    vis[u] = true;
    for (int v : graph[u])
    {
        if (vis[v])
            continue;
        DFS(v, d + 1);
    }
    vis[u] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{1}; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i{0}; i < N; i++)
        DFS(i, 1);
    cout << "0\n";
}