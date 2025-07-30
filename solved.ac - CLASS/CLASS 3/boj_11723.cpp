#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	set<int> S;
	int M; cin >> M;
	while(M--)
	{
		string order; cin >> order;
		if(order == "add")
		{
			int x; cin >> x;
			S.insert(x);
		}
		if(order == "remove")
		{
			int x; cin >> x;
			S.erase(x);
		}
		if(order == "check")
		{
			int x; cin >> x;
			if(S.find(x) != S.end()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		if(order == "toggle")
		{
			int x; cin >> x;
			if(S.find(x) != S.end()) S.erase(x);
			else S.insert(x);
		}
		if(order == "all")
		{
			for(int i=1; i<=20; i++)
			{
				if(S.find(i) == S.end())
					S.insert(i);
			} 
		}
		if(order == "empty")
		{
			S.clear();
		}
	}
}