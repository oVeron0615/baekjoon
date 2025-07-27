#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
int val[1001];
int graph[1001][2];
vector<int> V;
ll dp[2001][2001];
ll ans = 1;

ll nCr(int n, int c)
{
    if (dp[n][c] != -1)
        return dp[n][c];

    if (n == c)
        return 1;
    else if (c == 0)
        return dp[n][c] = 1;

    return dp[n][c] = (nCr(n - 1, c) + nCr(n - 1, c - 1)) % mod;
}

void inorder(int v)
{
    if (graph[v][0] != -1)
        inorder(graph[v][0]);

    V.push_back(val[v]);

    if (graph[v][1] != -1)
        inorder(graph[v][1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{1}; i <= N; i++)
        cin >> val[i] >> graph[i][0] >> graph[i][1];

    V.push_back(0);
    inorder(1);
    V.push_back(M + 1);

    memset(dp, -1, sizeof(dp));

    int cnt = 0;
    int l, r;
    for (int i{1}; i < V.size(); i++)
    {
        if (V[i] == -1)
        {
            if (V[i - 1] != -1)
                l = V[i - 1];
            cnt++;
        }
        else
        {
            if (cnt != 0)
            {
                r = V[i];
                ans = (ans * nCr(r - l - 1, cnt)) % mod;
            }
            cnt = 0;
        }
    }
    cout << ans << "\n";
}