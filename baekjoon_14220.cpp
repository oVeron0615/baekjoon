#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int n;
vector<pii> graph[501];
int dp[500][501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            int d;
            cin >> d;
            if (d != 0)
                graph[i].push_back({d, j});
        }
    }

    fill(&dp[1][0], &dp[499][501], INF);

    for (int i{0}; i < n - 1; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            if (dp[i][j] == INF)
                continue;

            for (auto [d, v] : graph[j])
                dp[i + 1][v] = min(dp[i + 1][v], dp[i][j] + d);
        }
    }

    int ans = INF;
    for (int i{1}; i <= n; i++)
        ans = min(ans, dp[n - 1][i]);

    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}