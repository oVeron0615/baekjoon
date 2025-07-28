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
	vector<int> A(N);
	for(int& Ai : A) cin >> Ai;
	sort(A.begin(), A.end());

	int M; cin >> M;
	while(M--)
	{
		int num; cin >> num;
		if(binary_search(A.begin(), A.end(), num)) cout << 1 << "\n";
		//binary_search : num이 A에 존재하는지 이분 탐색으로 확인
		else cout << 0 << "\n";
	}
}