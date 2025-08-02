#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string str; cin >> str;
	string explode; cin >> explode;
	string ans;
	for(char c : str)
	{
		ans += c;
		int ansLen = ans.length(), exLen = explode.length();
		if(ansLen >= exLen && ans.substr(ansLen-exLen, exLen) == explode)
		{
			for(int i=0; i<exLen; i++) ans.pop_back();
		}
	}

	if(ans.length()) cout << ans;
	else cout << "FRULA";
}