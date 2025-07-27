#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, Hcenti, T, H, temp, count{ 0 };
	priority_queue<int> pq;

	cin >> N >> Hcenti >> T;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> H;
		pq.push(H);
	}

	while (true)
	{
		if (Hcenti <= pq.top())
		{
			if (pq.top() != 1) temp = pq.top() / 2;
			else temp = 1;
			pq.pop();
			pq.push(temp);
			count++;
		}
		else break;

		if (count == T) break;
	}

	if (count < T) cout << "YES\n" << count;
	else
	{
		if(Hcenti <= pq.top()) cout << "NO\n" << pq.top();
		else cout << "YES\n" << count;
	}
}