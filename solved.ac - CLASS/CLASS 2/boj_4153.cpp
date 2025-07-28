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

	while(true)
	{
		int side1, side2, side3; cin >> side1 >> side2 >> side3;
		if(!side1 && !side2 && !side3) break;
		
		if(side1 < side2) swap(side1, side2);
		if(side1 < side3) swap(side1, side3);

		if(side1 * side1 == side2 * side2 + side3 * side3) cout << "right\n";
		else cout << "wrong\n";
	}
}