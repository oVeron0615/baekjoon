#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
int dist[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    fill(&dist[0][0], &dist[100][101], inf);
    for (int i{1}; i <= N; i++)
        dist[i][i] = 0;

    for (int i{1}; i <= M; i++)
    {
        int A, B;
        cin >> A >> B;
        dist[A][B] = 1;
    }

    for (int k{1}; k <= N; k++)
        for (int i{1}; i <= N; i++)
            for (int j{1}; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = 0;
    for (int i{1}; i <= N; i++)
    {
        int cnt = 0;
        for (int j{1}; j <= N; j++)
        {
            if (dist[i][j] == inf || i == j)
                continue;
            cnt++;
        }
        for (int j{1}; j <= N; j++)
        {
            if (dist[j][i] == inf || i == j)
                continue;
            cnt++;
        }

        if (cnt == N - 1)
            ans++;
    }
    cout << ans << "\n";
}