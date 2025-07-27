#include <iostream>
#include <array>
#include <climits>
using namespace std;

int main()
{
	int N;
	array<int, 100001> sq_number;

	cin >> N;
	for (int number{ 1 }; number <= N; number++)
	{
		int i, root;
		for (i = 1; i * i <= number; i++);
		root = i - 1;

		int min{ INT_MAX };
		for (int j{ 1 }; j <= root; j++)
		{
			int tempN{ number }, count{ 0 };
			count += tempN / (j * j);
			tempN %= (j * j);

			if (tempN != 0) count += sq_number[tempN];
			if (min > count) min = count;
		}
		
		sq_number[number] = min;
	}

	cout << sq_number[N];
}