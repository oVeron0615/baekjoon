#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

string str;

int solve(int l, int r, int ans)
{
    if (ans == 2)
        return ans;
    if (l > r)
        return ans;

    if (str[l] == str[r])
        return solve(l + 1, r - 1, ans);
    else
    {
        int ret{2};
        if (str[l + 1] == str[r])
            ret = min(ret, solve(l + 2, r - 1, ans + 1));
        if (str[l] == str[r - 1])
            ret = min(ret, solve(l + 1, r - 2, ans + 1));
        return ret;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> str;
        cout << solve(0, str.length() - 1, 0) << "\n";
    }
}