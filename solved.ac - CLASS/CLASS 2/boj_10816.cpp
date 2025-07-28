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
	vector<int> cards(N);
	for(int& card : cards) cin >> card;
	sort(cards.begin(), cards.end());

	int M; cin >> M;
	while(M--)
	{
		int num; cin >> num;
		cout << upper_bound(cards.begin(), cards.end(), num)
			- lower_bound(cards.begin(), cards.end(), num) << " ";
		//upper_bound : num보다 큰 수 중 가장 작은 수의 iterator return
		//lower_bound : num보다 작거나 같은 수 중 가장 큰 수의 iterator return
	}
}