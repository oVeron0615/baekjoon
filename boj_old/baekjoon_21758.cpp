#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
ll honey[100001];
ll psum[100001];
ll ans{0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{1}; i <= N; i++)
    {
        cin >> honey[i];
        psum[i] = psum[i - 1] + honey[i];
    }

    for (int i{2}; i < N; i++)
    {
        ll sum = (psum[N] - psum[1] - honey[i]) + (psum[N] - psum[i]);
        ans = max(ans, sum);
    }
    for (int i{1}; i < N - 1; i++)
    {
        ll sum = (psum[N - 1] - honey[i + 1]) + psum[i];
        ans = max(ans, sum);
    }
    for (int i{2}; i < N; i++)
    {
        ll sum = (psum[i] - psum[1]) + (psum[N - 1] - psum[i - 1]);
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}