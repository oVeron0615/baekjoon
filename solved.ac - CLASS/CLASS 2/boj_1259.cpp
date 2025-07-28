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

	string str; cin >> str;
	while(true)
	{
		if(str == "0") break;
		int l = 0, r = str.size() - 1;

		bool isPalindrome = true;
		while(l <= r)
		{
			if(str[l] != str[r]) isPalindrome = false;
			l++, r--;
		}

		if(isPalindrome) cout << "yes\n";
		else cout << "no\n";

		cin >> str;
	}
}