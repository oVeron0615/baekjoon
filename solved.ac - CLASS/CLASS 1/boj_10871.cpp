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
    
    int N, X; cin >> N >> X;
    int ans = 0;
    for(int i=1; i<=N; i++)
    {
        int Ai; cin >> Ai;
        if(Ai < X) cout << Ai << " ";
    }
}