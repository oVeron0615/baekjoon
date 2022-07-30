#include <iostream>
#include <string>
#include <stack>
#define inf 1e9
using namespace std;

int main()
{
	string S, s; cin >> S >> s;
	
	typedef pair<char, int> pci;
	stack<pci> st;
	int ind{ 0 };
	for (int i{ 0 }; i < S.size(); i++)
	{
		if (S[i] == s[ind])
		{
			st.push({ S[i], ind });
			ind++;
			if (ind == s.size())
			{
				while (!st.empty())
				{
					ind--;
					auto [c, k] = st.top();
					if (k == ind) st.pop();
					else
					{
						if (k == inf) ind = 0;
						else ind = k + 1;
						break;
					}
				}
				if (st.empty()) ind = 0;
			}
		}
		else
		{
			if (S[i] == s[0])
			{
				st.push({ S[i], 0 });
				ind = 1;
			}
			else
			{
				st.push({ S[i], inf });
				ind = 0;
			}
		}
	}

	stack<char> arr;
	while (!st.empty())
	{
		auto [c, k] = st.top(); st.pop();
		arr.push(c);
	}

	if (arr.empty()) cout << "FRULA";
	else
	{
		while (!arr.empty())
		{
			cout << arr.top(); arr.pop();
		}
	}
}