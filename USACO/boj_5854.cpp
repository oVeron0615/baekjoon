#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int N, K; cin >> N >> K;
    vector<pii> area;
    vector<int> point;

    int cur = 0;
    point.push_back(cur);
    for(int i=1; i<=N; i++)
    {
        int d; cin >> d;
        char c; cin >> c;
        cur += (c == 'R' ? d : -d);

        if(point.back() < cur) area.push_back({point.back(), cur});
        else area.push_back({cur, point.back()});
        point.push_back(cur);
    }

    sort(point.begin(), point.end());
    sort(area.begin(), area.end());

    vector<int> coat(N+1);
    for(auto [s, e] : area)
    {
        int sIdx = lower_bound(point.begin(), point.end(), s) - point.begin();
        int eIdx = lower_bound(point.begin(), point.end(), e) - point.begin();
        coat[sIdx]++; coat[eIdx]--;
    }

    int ans = 0;
    int coats = coat[0];
    for(int i=1; i<=N; i++)
    {
        if(coats >= K) ans += point[i] - point[i-1];
        coats += coat[i];
    }
    cout << ans;
} 