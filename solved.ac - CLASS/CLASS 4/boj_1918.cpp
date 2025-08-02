#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int priority(char c)
{
	if(c == '(') return 2;
	if(c == '+' || c == '-') return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	stack<char> st;
	string str; cin >> str;
	str = '(' + str + ')';

	for(char c : str)
	{
		if(isalpha(c)) 
		{
			cout << c;
			continue;
		}

		if(c == '(') st.push(c);
		else if(c == ')')
		{
			while(st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
			continue;
		}
		else
		{
			while(priority(c) >= priority(st.top()))
			{
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
	}
}