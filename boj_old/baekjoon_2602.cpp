#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

string str;
string bridge[2];
int dp[20][2][100];

int solve(int k, int i, int j)
{
    if (k == str.size())
        return 1;
    if (j == bridge[i].size())
        return 0;

    if (dp[k][i][j] != -1)
        return dp[k][i][j];

    int &ret = dp[k][i][j];
    ret = 0;

    if (str[k] == bridge[i][j])
        ret += solve(k + 1, 1 - i, j + 1);
    ret += solve(k, i, j + 1);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> str >> bridge[0] >> bridge[1];
    cout << solve(0, 0, 0) + solve(0, 1, 0);
}