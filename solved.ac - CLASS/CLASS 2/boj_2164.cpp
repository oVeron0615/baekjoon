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
	queue<int> cards;
	for(int i=1; i<=N; i++) cards.push(i);

	while(cards.size() > 1)
	{
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}
	cout << cards.front();
}