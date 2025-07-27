#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int n;
string tel[10000];

void solve()
{
    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> tel[i];

    sort(tel, tel + n);

    for (int i{0}; i < n - 1; i++)
    {
        if (tel[i + 1].substr(0, tel[i].length()) == tel[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}