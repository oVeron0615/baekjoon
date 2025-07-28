#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool isBalanced(string& str)
{
	stack<char> st;
	for(char c : str)
	{
		if(c == '(' || c == '[') st.push(c);
		else if(c == ')')
		{
			if(st.empty() || st.top() != '(') return false;
			st.pop();
		}
		else if(c == ']')
		{
			if(st.empty() || st.top() != '[') return false;
			st.pop();
		}
	}

	return st.empty();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string str; 
	while(true)
	{
		getline(cin, str);
		if(str == ".") break;

		if(isBalanced(str)) cout << "yes\n";
		else cout << "no\n";
	}
}