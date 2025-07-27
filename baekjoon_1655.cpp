#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, n, mid, temp;
	priority_queue<int> down;
	priority_queue<int, vector<int>, greater<int>> up;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		cin >> n;
		if (i == 1) mid = n;
		else if (i % 2 == 1)
		{
			if (n < down.top())
			{
				down.push(n);
				mid = down.top();
				down.pop();
			}
			else if (n > up.top())
			{
				up.push(n);
				mid = up.top();
				up.pop();
			}
			else mid = n;
		}
		else
		{
			if (n < mid)
			{
				down.push(n);
				up.push(mid);
			}
			else
			{
				down.push(mid);
				up.push(n);
			}
			mid = down.top();
		}

		cout << mid << "\n";
	}
}