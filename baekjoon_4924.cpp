#include <bits/stdc++.h>
#define AR 1000000
#define INF 1e18
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

ll val[AR + 1];
ll p[AR + 1];
ll psum[AR + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i{1}; i <= AR; i++)
        val[i] = i;

    for (int i{2}; i <= AR; i++)
    {
        if (val[i] == i)
        {
            p[i] = -1;
            for (int j{i * 2}; j <= AR; j += i)
            {
                while (val[j] % i == 0)
                {
                    val[j] /= i;
                    p[j]++;
                }
            }
        }
    }

    for (int i{1}; i <= AR; i++)
        p[i]--;
    for (int i{1}; i <= AR; i++)
        psum[i] = psum[i - 1] + p[i];

    int tc = 1;
    int L, U;
    cin >> L >> U;
    while (L != -1 && U != -1)
    {
        ll mn = psum[L - 1], mx = psum[L - 1];
        ll ans = -INF;
        for (int i{L}; i <= U; i++)
        {
            if (mn > psum[i])
            {
                mn = mx = psum[i];
                ans = max(ans, p[i]);
            }
            else
            {
                mx = max(mx, psum[i]);
                ans = max(ans, mx - mn);
            }
        }

        cout << tc++ << ". " << ans << "\n";
        cin >> L >> U;
    }
}