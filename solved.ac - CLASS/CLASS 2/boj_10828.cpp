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
	stack<int> st;
	while(N--)
	{
		string order; cin >> order;
		if(order == "push")
		{
			int X; cin >> X;
			st.push(X);
		}
		if(order == "pop")
		{
			if(st.empty()) cout << -1 << "\n";
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		if(order == "size")
		{
			cout << st.size() << "\n";
		}
		if(order == "empty")
		{
			cout << st.empty() << "\n";
		}
		if(order == "top")
		{
			if(st.empty()) cout << -1 << "\n";
			else cout << st.top() << "\n";
		}
	}
}