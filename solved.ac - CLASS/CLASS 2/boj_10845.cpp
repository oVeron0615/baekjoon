#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	queue<int> qu;
	while(N--)
	{
		string order; cin >> order;
		if(order == "push")
		{
			int X; cin >> X;
			qu.push(X);
		}
		if(order == "pop")
		{
			if(qu.empty()) cout << -1 << "\n";
			else
			{
				cout << qu.front() << "\n";
				qu.pop();
			}
		}
		if(order == "size")
		{
			cout << qu.size() << "\n";
		}
		if(order == "empty")
		{
			cout << qu.empty() << "\n";
		}
		if(order == "front")
		{
			if(qu.empty()) cout << -1 << "\n";
			else cout << qu.front() << "\n";
		}
		if(order == "back")
		{
			if(qu.empty()) cout << -1 << "\n";
			else cout << qu.back() << "\n";
		}
	}
}