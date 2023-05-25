#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

ll W, H, K, N, M;
vector<ll> row, col;
ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> W >> H >> K;

    int r = 0;
    cin >> N;
    for (int i{1}; i <= N; i++)
    {
        int y;
        cin >> y;
        row.push_back(y - r);
        r = y;
    }
    row.push_back(H - r);

    int c = 0;
    cin >> M;
    for (int i{1}; i <= M; i++)
    {
        int x;
        cin >> x;
        col.push_back(x - c);
        c = x;
    }
    col.push_back(W - c);

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    ll p1 = 0, p2 = col.size() - 1;
    while (p1 < row.size() && p2 >= 0)
    {
        if (row[p1] * col[p2] > K)
            p2--;
        else
        {
            ans += p2 + 1;
            p1++;
        }
    }
    cout << ans << "\n";
}