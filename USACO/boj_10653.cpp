#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 501;
const int INF = 1e9;
int N, K;
int x[MAXN], y[MAXN];
int dp[MAXN][MAXN];

int dist(int i1, int i2)
{
    return abs(x[i1] - x[i2]) + abs(y[i1] - y[i2]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> x[i] >> y[i];

    fill(&dp[0][0], &dp[0][0] + MAXN*MAXN, INF);
    dp[1][K] = 0;
    for(int i=1; i<N; i++)
    {
        for(int j=K; j>=0; j--)
        {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(i, i+1));
            for(int k=1; k<=j && i+k+1<=N; k++)
            {
                dp[i+k+1][j-k] = min(dp[i+k+1][j-k], dp[i][j] + dist(i, i+k+1));
            }
        }
    }

    int ans = INF;
    for(int j=K; j>=0; j--)
    {
        ans = min(ans, dp[N][j]);
    }
    cout << ans;
} 