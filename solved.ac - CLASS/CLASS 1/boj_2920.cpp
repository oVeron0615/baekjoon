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

    vector<int> music(8);
    for(int& musici : music) cin >> musici;
    vector<int> ascd = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> dscd = {8, 7, 6, 5, 4, 3, 2, 1};

    if(music == ascd) cout << "ascending";
    else if(music == dscd) cout << "descending";
    else cout << "mixed";
}