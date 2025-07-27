#include <iostream>
#include <array>
using namespace std;

int main()
{
	int N, realmax{ 0 };
	array<array<int, 2>, 1000> A;

	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> A[i][0];
		A[i][1] = 1;
	}

	for (int i{ N - 1 }; i >= 0; i--)
	{
		int max{ 0 };
		for (int j{ i + 1 }; j < N; j++)
		{
			if (A[i][0] < A[j][0] && max < A[j][1]) max = A[j][1];
		}
		A[i][1] += max;
		if (realmax < A[i][1]) realmax = A[i][1];
	}

	cout << realmax;
}