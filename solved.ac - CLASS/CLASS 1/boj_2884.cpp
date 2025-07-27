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
    
    int H, M; cin >> H >> M;
    if(M >= 45) cout << H << " " << M - 45;
    else if(H >= 1) cout << H - 1 << " " << M + 15;
    else cout << 23 << " " << M + 15;
}