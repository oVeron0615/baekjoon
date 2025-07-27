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

    vector<bool> mod(42, false);
    for(int i=1; i<=10; i++)
    {
        int input; cin >> input;
        mod[input % 42] = true;
    }
    
    int ans = 0;
    for(bool isMod : mod)
        if(isMod) ans++;
    cout << ans;
}