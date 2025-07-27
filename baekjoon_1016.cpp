#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

ll mn, mx;
bool notPrime[1000001];
bool sieve[1000001];
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    notPrime[1] = true;
    for (int i{2}; i * i <= 1000000; i++)
    {
        if (notPrime[i])
            continue;

        for (int j{i * 2}; j <= 1000000; j += i)
            notPrime[j] = true;
    }

    cin >> mn >> mx;
    for (ll i{2}; i * i <= mx; i++)
    {
        if (notPrime[i])
            continue;

        ll n = mn / (i * i) * (i * i);
        for (ll j{n}; j <= mx; j += (i * i))
        {
            if (j - mn >= 0)
                sieve[j - mn] = true;
        }
    }

    for (int i{0}; i <= mx - mn; i++)
    {
        if (!sieve[i])
            ans++;
    }

    cout << ans << "\n";
}