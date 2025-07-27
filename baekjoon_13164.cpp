#include <bits/stdc++.h>
#define inf -1e18
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, K;
int h1, h2;
priority_queue<int, vector<int>> pq;
int ans{0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    cin >> h1;
    for (int i{2}; i <= N; i++)
    {
        cin >> h2;
        pq.push(h2 - h1);
        ans += h2 - h1;
        h1 = h2;
    }

    for (int i{1}; i < K; i++)
    {
        ans -= pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}