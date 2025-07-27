#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;

	cin >> T;
	for (int i{ 0 }; i < T; i++)
	{
		priority_queue<int, vector<int>> less;
		priority_queue<int, vector<int>, greater<int>> great;

		int M, number, mid;
		cin >> M;
		cout << M / 2 + 1 << "\n";

		for (int i{ 0 }; i < M; i++)
		{
			cin >> number;

			int count{ 0 };
			if (i % 2 == 0)
			{
				mid = number;
				if (!less.empty() && less.top() > mid)
				{
					int temp{less.top()};
					less.pop();
					less.push(mid);
					mid = temp;
				}
				if (!great.empty() && great.top() < mid)
				{
					int temp{ great.top() };
					great.pop();
					great.push(mid);
					mid = temp;
				}
				cout << mid << " ";
				count++;
				if (count == 10)
				{
					cout << "\n";
					count = 0;
				}
			}
			else
			{
				int small{ mid < number ? mid : number };
				int big{ mid >= number ? mid : number };

				less.push(small);
				great.push(big);
			}
		}
	}
}