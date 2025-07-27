#include <iostream>
#include <array>
using namespace std;

int N, ans{ 0 };
array<bool, 15> row, col;
array<bool, 30> dia1, dia2;

void f(int loc);
bool isValid(int loc, int i);
void setQueen(int loc, int i);

int main()
{
	cin >> N;
	f(0);
	cout << ans;
}

void f(int loc)
{
	if (loc == N)
	{
		ans++;
		return;
	}

	for (int i{ 0 }; i < N; i++)
	{
		if (isValid(loc, i))
		{
			setQueen(loc, i);
			f(loc + 1);
			setQueen(loc, i);
		}
	}
}

bool isValid(int loc, int i)
{
	return !(row[loc] || col[i] || dia1[loc - i + N - 1] || dia2[loc + i]);
}

void setQueen(int loc, int i)
{
	row[loc] ^= 1;
	col[i] ^= 1;
	dia1[loc - i + N - 1] ^= 1;
	dia2[loc + i] ^= 1;
}