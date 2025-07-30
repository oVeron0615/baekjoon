#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--)
	{
		multiset<int> pq;

		int k; cin >> k;
		while(k--)
		{
			char c; cin >> c;
			int x; cin >> x;
			if(c == 'I') pq.insert(x);
			else
			{
				if(pq.empty()) continue;
				if(x == -1) pq.erase(pq.begin());
				else pq.erase(--pq.end());
			}
		}
		
		if(pq.empty()) cout << "EMPTY\n";
		else cout << *(--pq.end()) << " " << *(pq.begin()) << "\n";
	}
}