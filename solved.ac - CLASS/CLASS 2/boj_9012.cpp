#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool isVPS(string& str)
{
	stack<char> st;
	for(char c : str)
	{
		if(c == '(') st.push(c);
		else
		{
			if(st.empty() || st.top() != '(') return false;
			st.pop();
		}
	}

	return st.empty();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	while(N--)
	{
		string str; cin >> str;

		if(isVPS(str)) cout << "YES\n";
		else cout << "NO\n";
	}
}