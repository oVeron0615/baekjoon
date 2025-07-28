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

	vector<bool> isNum(2'000'001, false);
	int N; cin >> N;
	while(N--)
	{
		int num; cin >> num;
		isNum[num + 1'000'000] = true;
	}

	for(int i=0; i<2'000'001; i++)
		if(isNum[i]) cout << i - 1'000'000 << "\n";
}