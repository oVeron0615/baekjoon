#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

auto cmp = [](int a, int b)
{
	if(abs(a) == abs(b)) return !(a < b);
	else return !(abs(a) < abs(b));
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
	int N; cin >> N;
	while(N--)
	{
		int x; cin >> x;
		if(x == 0)
		{
			if(pq.empty()) cout << 0 << "\n";
			else 
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(x);
	}
}