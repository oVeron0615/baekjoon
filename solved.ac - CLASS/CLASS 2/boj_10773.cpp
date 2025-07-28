#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int K; cin >> K;
	stack<int> st;
	while(K--)
	{
		int num; cin >> num;
		if(num == 0) st.pop();
		else st.push(num);
	}

	int ans = 0;
	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	cout << ans;
}