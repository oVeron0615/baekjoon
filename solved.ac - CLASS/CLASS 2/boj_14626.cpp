#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string ISBM; cin >> ISBM;
	for(int ans=0; ans<=9; ans++)
	{
		int sum = 0;
		for(int i=0; i<13; i++)
		{
			if(i % 2 == 0) 
			{
				if(ISBM[i] == '*') sum += ans;
				else sum += ISBM[i] - '0';
			}
			else
			{
				if(ISBM[i] == '*') sum += ans * 3;
				else sum += (ISBM[i] - '0') * 3;
			} 
		}

		if(sum % 10 == 0)
		{
			cout << ans;
			return 0;
		}
	}
}