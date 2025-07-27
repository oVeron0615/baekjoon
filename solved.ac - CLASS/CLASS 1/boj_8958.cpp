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

    int T; cin >> T;
    while(T--)
    {
        string OX; cin >> OX;
        int ans = 0, seqO = 0;
        for(char c : OX)
        {
            if(c == 'O') ++seqO, ans += seqO;
            else seqO = 0;
        }
        cout << ans << "\n";
    }
}