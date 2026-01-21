#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int N; cin >> N;
    vector<ll> psum(N+1);
    for(int i=1; i<=N; i++) 
    {
        ll cake; cin >> cake;
        psum[i] = psum[i-1] + cake;
    }

    ll b = 1e18;
    for(int i=N/2+1; i<=N; i++) 
    {
        b = min(b, psum[i] - psum[i - N/2 - 1]);
    }
    ll e = psum[N] - b;

    cout << b << " " << e << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) solve();
}