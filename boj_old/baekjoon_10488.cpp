#include <bits/stdc++.h>
#define pi 3.14159265358979
#define bound 1296000
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

void solve()
{
    ld r, n, d, m, s;
    cin >> r >> n >> d >> m >> s;

    int sum = 0;
    bool check[bound + 1] = {};
    vector<int> degs;
    for (int i{1}; i <= n; i++)
    {
        sum += d * 60 * 60 + m * 60 + s;
        sum %= bound;

        if (check[sum])
            break;
        check[sum] = true;

        degs.push_back(sum);
    }
    sort(degs.begin(), degs.end());

    int mx = 0;
    for (int i{1}; i < degs.size(); i++)
        mx = max(mx, degs[i] - degs[i - 1]);
    mx = max(mx, degs[0] + bound - degs[degs.size() - 1]);

    cout << fixed << setprecision(6) << r * r * mx / 3600 * pi / 360 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int m;
    cin >> m;
    while (m--)
        solve();
}