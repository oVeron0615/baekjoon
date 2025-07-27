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
    
    int A, B, C; cin >> A >> B >> C;
    string result = to_string(A * B * C);

    vector<int> numCount(10, 0);
    for(char c : result) numCount[c - '0']++;

    for(int numCounti : numCount) cout << numCounti << "\n";
}