#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	map<string, int> name_num;
	map<int, string> num_name;
	
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		string name; cin >> name;
		name_num[name] = i;
		num_name[i] = name;
	}

	while(M--)
	{
		string order; cin >> order;
		if(isalpha(order[0])) cout << name_num[order] << "\n";
		else cout << num_name[stoi(order)] << "\n";
	}
}