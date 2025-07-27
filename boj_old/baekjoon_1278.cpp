#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> stage;

void f(int, int, int);

int main()
{
	int N; cin >> N;
	int sum{ 0 };
	for (int i{ 0 }; i < N; i++)
	{
		sum += pow(2, i);
	}
	cout << sum << "\n";
	f(1, N, 0);
	cout << 1;
}

void f(int a, int b, int k)
{
	if (k % 2 == 1)
	{
		for (int i{ a }; i <= b; i++)
		{
			if (i == a)
			{
				stage.insert(i);
				cout << i << "\n";
			}

			if (a == b) return;
			f(i + 1, b, k + 1);

			if (i != b)
			{
				stage.erase(i);
				cout << i << "\n";
			}
		}
	}
	else
	{
		for (int i{ b }; i >= a; i--)
		{
			if (i == b)
			{
				stage.insert(i);
				cout << i << "\n";
			}

			if (a == b) return;
			f(a, i - 1, k + 1);

			if (i != a)
			{
				stage.erase(i);
				cout << i << "\n";
			}
		}
	}
}