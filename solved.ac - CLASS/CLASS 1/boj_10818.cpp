#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    int N; cin >> N;
    int minVal = 1'000'000, maxVal = -1'000'000;
    for(int i=1; i<=N; i++)
    {
        int integer; cin >> integer;
        minVal = min(minVal, integer);
        maxVal = max(maxVal, integer);
    }
    cout << minVal << " " << maxVal;
}