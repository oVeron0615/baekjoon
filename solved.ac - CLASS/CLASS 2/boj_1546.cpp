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
	vector<int> grade(N);
	for(int& i : grade) cin >> i;
	
	int M = 0, sum = 0;
	for(int gradei : grade) 
		M = max(M, gradei), sum += gradei;
	
	cout << fixed << setprecision(2) << double(sum * 100) / (N * M);
}