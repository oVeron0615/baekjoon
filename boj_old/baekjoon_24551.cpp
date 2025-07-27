#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

ll N;
vector<ll> v;
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    string s = "11";
    while (N >= stoll(s))
    {
        bool check = true;
        for (ll val : v)
        {
            if (stoll(s) % val == 0)
            {
                check = false;
                break;
            }
        }

        if (check)
            v.push_back(stoll(s));
        s += '1';
    }

    for (int S{1}; S < (1 << v.size()); S++)
    {
        int cnt = 0;
        ll val = 1;
        bool tooBig = false;

        for (int i{0}; (1 << i) <= S; i++)
        {
            if (S & (1 << i))
            {
                if (N / v[i] < val)
                {
                    tooBig = true;
                    break;
                }
                val *= v[i];
                cnt++;
            }
        }

        if (tooBig)
            continue;

        if (cnt % 2)
            ans += N / val;
        else
            ans -= N / val;
    }
    cout << ans << "\n";
}