#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
	string p; cin >> p;
	int n; cin >> n;

	deque<int> dq;
	string str; cin >> str;
	string num = "";
	for(char c : str)
	{
		if(isdigit(c)) num += c;
		else
		{
			if(num != "") dq.push_back(stoi(num));
			num = "";
		}
	}

	bool isFront = true;
	for(char c : p)
	{
		if(c == 'R') isFront = !isFront;
		else
		{
			if(dq.empty()) 
			{
				cout << "error\n";
				return;
			}
			else
			{
				if(isFront) dq.pop_front();
				else dq.pop_back();
			}
		}
	}

	cout << "[";
	while(!dq.empty())
	{
		if(isFront)
		{
			cout << dq.front();
			dq.pop_front();
		}
		else
		{
			cout << dq.back();
			dq.pop_back();
		}
		
		if(dq.empty()) continue;
		cout << ",";
	}
	cout << "]\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}