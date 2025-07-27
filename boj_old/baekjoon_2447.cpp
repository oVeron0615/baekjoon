#include <iostream>
#include <array>
#define MAX 6561
using namespace std;

array<array<char, MAX>, MAX> star;

void self(int N, int start, int c, array<array<char, MAX>, MAX>& star);

int main()
{
	int N;

	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			star[i][j] = '*';
		}
	}

	self(N, N, 1, star);

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cout << star[i][j];
		}
		cout << "\n";
	}
}

void self(int N, int start, int c, array<array<char, MAX>, MAX>& star)
{
	int k = N / c;
	for (int i{ start / 3 }; i < N; i += k)
	{
		for (int j{ start / 3 }; j < N; j += k)
		{
			for (int p{ i }; p < i + k / 3; p++)
			{
				for (int q{ j }; q < j + k / 3; q++)
				{
					star[p][q] = ' ';
				}
			}
		}
	}

	if (start == 1) return;
	self(N, start / 3, c * 3, star);
}