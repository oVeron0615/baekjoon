#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
ll T[1500001];
ll P[1500001];
ll dp[2][1500001];

ll solve(int isCon, int day)
{
    if (day > N)
        return 0;
    if (dp[isCon][day] != -1)
        return dp[isCon][day];

    if (isCon)
    {
        if (day + T[day] - 1 <= N)
        {
            dp[isCon][day] =
                max(solve(isCon, day + T[day]),
                    solve(1 - isCon, day + T[day])) +
                P[day];
        }
    }
    else
    {
        dp[isCon][day] =
            max(solve(isCon, day + 1),
                solve(1 - isCon, day + 1));
    }
    return dp[isCon][day];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{1}; i <= N; i++)
        cin >> T[i] >> P[i];

    memset(dp, -1, sizeof(dp));
    cout << max(solve(0, 1), solve(1, 1)) << "\n";
}