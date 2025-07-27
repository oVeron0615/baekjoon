#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	int T, K, file;
	cin >> T;

	for (int i{ 0 }; i < T; i++)
	{
		int sum{ 0 };

		cin >> K;
		for (int i{ 0 }; i < K; i++)
		{
			cin >> file;
			pq.push(file);
		}
		while (pq.size() > 1)
		{
			int f{ 0 };
			f += pq.top(); pq.pop();
			f += pq.top(); pq.pop();
			sum += f;
			pq.push(f);
		}
		pq.pop();
		cout << sum << "\n";
	}
}