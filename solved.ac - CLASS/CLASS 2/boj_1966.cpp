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
		int N, M; cin >> N >> M;
		queue<int> qu;
		vector<int> pri;
		while(N--)
		{
			int doc; cin >> doc;
			qu.push(doc);
			pri.push_back(doc);
		}

		sort(pri.begin(), pri.end(), greater<int>());
		int priIdx = 0;

		int ans = 0;
		while(!qu.empty())
		{
			if(pri[priIdx] == qu.front())
			{
				if(M == 0)
				{
					cout << priIdx + 1 << "\n";
					break;
				}
				qu.pop();
				M--, priIdx++;
			}
			else
			{
				qu.push(qu.front());
				qu.pop();

				if(M == 0) M = qu.size() - 1;
				else M--;
			}
		}
	}
}