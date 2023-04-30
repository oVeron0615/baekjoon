#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

ll N, M;
ll table[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i{1}; i <= N; i++)
        cin >> table[i];

    ll lef = 0, rig = 1e18;
    while (lef < rig)
    {
        ll mid = (lef + rig) / 2;
        ll sum = 0;

        for (int i{1}; i <= N; i++)
        {
            sum += mid / table[i];
            if (sum > 1e18)
                break;
        }

        if (sum < M)
            lef = mid + 1;
        else
            rig = mid;
    }
    cout << rig << "\n";
}