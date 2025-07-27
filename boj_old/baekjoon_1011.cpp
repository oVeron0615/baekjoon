#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		int x, y; cin >> x >> y;
		int m{ y - x };

		long long sum{};
		int cnt{ 2 };
		while (true)
		{
			sum += cnt / 2;
			cnt++;
			if (sum >= m) break;
		}
		cout << cnt - 2 << "\n";
	}
}