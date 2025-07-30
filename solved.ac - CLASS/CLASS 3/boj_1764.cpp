#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	set<string> names, ans;
	while(N--)
	{
		string name; cin >> name;
		names.insert(name);
	}
	while(M--)
	{
		string name; cin >> name;
		if(names.find(name) != names.end()) ans.insert(name);
	}

	cout << ans.size() << "\n";
	for(auto i=ans.begin(); i != ans.end(); i++) cout << *i << "\n";
}