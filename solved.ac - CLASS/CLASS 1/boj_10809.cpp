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

    string S; cin >> S;
    vector<int> alpha(26, -1);
    for(int i=0; i<S.length(); i++)
        if(alpha[S[i] - 'a'] == -1) alpha[S[i] - 'a'] = i;
    
    for(int alphai : alpha) cout << alphai << " ";
}