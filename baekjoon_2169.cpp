#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
int val[1001][1001];
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{ 1 }; i <= N; i++)
        for (int j{ 1 }; j <= M; j++)
            cin >> val[i][j];

    for (int i{ 1 }; i <= M; i++)
        dp[1][i] = dp[1][i - 1] + val[1][i];

    for (int i{ 2 }; i <= N; i++)
    {
        int lval = -inf;
        for (int j{ 1 }; j <= M; j++)
        {
            lval = max(lval, dp[i - 1][j]) + val[i][j];
            dp[i][j] = lval;
        }

        int rval = -inf;
        for (int j{ M }; j >= 1; j--)
        {
            rval = max(rval, dp[i - 1][j]) + val[i][j];
            dp[i][j] = max(dp[i][j], rval);
        }
    }
    cout << dp[N][M];
}