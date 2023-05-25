#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, M;
int task[3][4];
int ans = 0;

void solve(int cnt, int bef, int sum)
{
    if (cnt == N)
    {
        if (sum >= M)
            ans++;
        return;
    }

    for (int i{1}; i <= 2; i++)
    {
        for (int j{1}; j <= 3; j++)
        {
            if (bef == j)
                solve(cnt + 1, j, sum + task[i][j] / 2);
            else
                solve(cnt + 1, j, sum + task[i][j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{1}; i <= 2; i++)
        for (int j{1}; j <= 3; j++)
            cin >> task[i][j];

    solve(0, 0, 0);
    cout << ans << "\n";
}