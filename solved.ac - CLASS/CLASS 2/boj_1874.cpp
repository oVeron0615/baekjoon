#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	stack<int> st;
	vector<char> ans;
	int num = 1;
	while(n--)
	{
		int a; cin >> a;
		if(st.empty() || st.top() <= a)
		{
			while(num <= a)
			{
				st.push(num++);
				ans.push_back('+');
			}
			st.pop();
			ans.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for(char c : ans) cout << c << "\n";
}