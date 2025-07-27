#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int, 10001> integer{}, plus{};
	int n, k, coin;

	cin >> n >> k;
	for (int i{ 0 }; i < n; i++)
	{
		cin >> coin;
		for (int l{ 0 }; l <= k; l++)
		{
			if (l == 0)
			{
				for (int j{ 1 }; j * coin <= k; j++)
				{
					plus[j * coin]++;
				}
			}
			else if(integer[l] != 0)
			{
				for (int j{ 1 }; j * coin <= k; j++)
				{
					if(l + j * coin <= k) plus[l + j * coin] += integer[l];
				}
			}
		}

		for (int j{ 1 }; j <= k; j++)
		{
			integer[j] += plus[j];
			plus[j] = 0;
		}
	}
	cout << integer[k];
}