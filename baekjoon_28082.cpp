#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, K;
int bat[501];
int dp[50001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for (int i{1}; i <= N; i++)
        cin >> bat[i];

    fill(&dp[0], &dp[50001], inf);
    dp[50000] = 0;

    for (int i{1}; i <= N; i++)
    {
        for (int j{50000}; j >= 1; j--)
        {
            if (j - bat[i] >= 0 && dp[j - bat[i]] < K)
                dp[j] = min(dp[j], dp[j - bat[i]] + 1);
        }
    }

    int cnt = 0;
    for (int i{1}; i <= 50000; i++)
        if (dp[i] != inf)
            cnt++;

    cout << cnt << "\n";
    for (int i{1}; i <= 50000; i++)
        if (dp[i] != inf)
            cout << 50000 - i << " ";
}