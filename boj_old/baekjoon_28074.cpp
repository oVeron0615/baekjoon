#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

bool alpha[26];
string S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S;
    for (char c : S)
        alpha[c - 'A'] = true;

    if (alpha['M' - 'A'] && alpha['O' - 'A'] && alpha['B' - 'A'] && alpha['I' - 'A'] && alpha['S' - 'A'])
        cout << "YES\n";
    else
        cout << "NO\n";
}