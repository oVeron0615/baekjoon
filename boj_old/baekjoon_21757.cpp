#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
int psum[100001];
ll dp[5][100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{1}; i <= N; i++)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    if (psum[N] % 4 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    dp[0][0] = 1;
    for (int i{1}; i <= 4; i++)
    {
        for (int j{1}; j <= N; j++)
            dp[i - 1][j] += dp[i - 1][j - 1];

        for (int j{1}; j <= N; j++)
        {
            if (psum[j] == psum[N] / 4 * i)
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[4][N] << "\n";
}