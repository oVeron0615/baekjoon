#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	map<string, string> address_password;
	int N, M; cin >> N >> M;
	while(N--)
	{
		string address, password; cin >> address >> password;
		address_password[address] = password;
	}
	while(M--)
	{
		string address; cin >> address;
		cout << address_password[address] << "\n";
	}
}