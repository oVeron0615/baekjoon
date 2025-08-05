#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1'000'001;
	int A[MAXN];

	int N; cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	vector<int> lastVal;
	for(int i=1; i<=N; i++)
	{
		auto iter = lower_bound(lastVal.begin(), lastVal.end(), A[i]);
		if(iter == lastVal.end()) lastVal.push_back(A[i]);
		else *iter = A[i];
	}
	cout << lastVal.size();
}