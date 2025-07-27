#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

string str;
string PPAP;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> str;
	for (char c : str)
	{
		PPAP += c;
		if (PPAP.length() >= 4)
		{
			if (PPAP.substr(PPAP.length() - 4) == "PPAP")
			{
				for (int i{1}; i <= 3; i++)
					PPAP.pop_back();
			}
		}
	}

	if (PPAP == "P")
		cout << "PPAP\n";
	else
		cout << "NP\n";
}