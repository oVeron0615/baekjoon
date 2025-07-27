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
        int R; cin >> R;
        string S; cin >> S;
        for(char c : S)
            for(int i=1; i<=R; i++) 
                cout << c;
        cout << "\n";
    }
}