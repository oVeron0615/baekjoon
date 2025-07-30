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
	vector<int> X;
	set<int> sortedX;
	for(int i=1; i<=N; i++)
	{
		int Xi; cin >> Xi;
		X.push_back(Xi);
		sortedX.insert(Xi);
	}

	map<int, int> CC;
	int idx = 0;
	for(auto i = sortedX.begin(); i != sortedX.end(); i++) CC[*i] = idx++;

	for(int Xi : X) cout << CC[Xi] << " ";
}