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
    
    int maxVal = 0, maxValPos;
    for(int pos=1; pos<=9; pos++)
    {
        int number; cin >> number;
        if(maxVal < number) maxVal = number, maxValPos = pos;
    }
    cout << maxVal << "\n" << maxValPos;
}