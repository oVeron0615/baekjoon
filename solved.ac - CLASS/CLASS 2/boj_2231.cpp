#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	int M = 1;
	while(M++ <= N)
	{
		int decomp = M;
		string str = to_string(decomp);
		for(char c : str) decomp += c - '0';

		if(decomp == N)
		{
			cout << M;
			exit(0);
		}
	}
	cout << 0;
}