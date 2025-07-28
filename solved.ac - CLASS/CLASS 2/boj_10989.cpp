#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

//계수 정렬
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> cnt(10001, 0);

	for(int i=1; i<=N; i++)
	{
		int num; cin >> num;
		cnt[num]++;
	}

	for(int i=1; i<=10000; i++)
	{
		for(int j=1; j<=cnt[i]; j++)
		{
			cout << i << "\n";
		}
	}
}