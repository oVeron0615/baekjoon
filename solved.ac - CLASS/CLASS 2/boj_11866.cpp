#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K; cin >> N >> K;
	queue<int> qu;
	for(int i=1; i<=N; i++) qu.push(i);

	cout << "<";
	while(!qu.empty())
	{
		for(int i=1; i<K; i++)
		{
			qu.push(qu.front());
			qu.pop();
		}

		cout << qu.front();
		qu.pop();
		if(!qu.empty()) cout << ", ";
	}
	cout << ">";
}