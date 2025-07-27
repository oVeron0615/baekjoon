#include <iostream>
#include <vector>
using namespace std;

bool number[4000001];
vector<int> pnsum(1, 0);

int main()
{
	int N; cin >> N;
	long long sum{ 0 };

	for (int i{ 2 }; i <= N; i++)
	{
		if (number[i]) continue;
		else
		{
			sum += i;
			pnsum.push_back(sum);

			for (int j{ i * 2 }; j <= N; j += i)
			{
				number[j] = true;
			}
		}
	}

	int p1{ 0 }, p2{ 1 }, cnt{ 0 };
	while (p2 < pnsum.size())
	{
		if (pnsum[p2] - pnsum[p1] < N) p2++;
		else if (pnsum[p2] - pnsum[p1] > N) p1++;
		else
		{
			cnt++;
			p2++;
		}
	}
	cout << cnt;
}