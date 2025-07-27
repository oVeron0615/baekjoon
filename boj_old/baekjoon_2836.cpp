#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M; cin >> N >> M;
    vector<pll> gogi;
    for (int i{ 0 }; i < N; i++)
    {
        ll gi, go; cin >> gi >> go;
        if (gi > go)
            gogi.push_back({ go, gi });
    }
    sort(gogi.begin(), gogi.end());

    ll s = 0, e = 0;
    ll ans = M;
    for (auto [go, gi] : gogi)
    {
        if (e < go)
        {
            ans += (e - s) * 2;
            s = go, e = gi;
        }
        else
        {
            if (s <= go && go <= e)
                e = max(e, gi);
        }
    }
    ans += (e - s) * 2;

    cout << ans;
}