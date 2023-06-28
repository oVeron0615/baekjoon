#include <bits/stdc++.h>
#define bound 1e9
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    int L, R;
    cin >> L >> R;

    int cnt[100001][2] = {};
    for (int i{1}; i * i <= R; i++)
    {
        int s;
        if (L % i == 0)
            s = L;
        else
            s = L / i * i + i;

        for (int j{s}; j <= R; j += i)
        {
            if (i > j / i)
                continue;

            if (i % 2 == 0)
                cnt[j - L][0]++;
            else
                cnt[j - L][1]++;

            if (j / i % 2 == 0)
                cnt[j - L][0]++;
            else
                cnt[j - L][1]++;
        }
    }

    int ans = 0;
    for (int i{0}; i <= R - L; i++)
    {
        if (abs(cnt[i][0] - cnt[i][1]) <= 2)
            ans++;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int i{1}; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}