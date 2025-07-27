#include <iostream>
#include <array>
using namespace std;

array<array<int, 9>, 9> sudoku;

void f(int x, int y);
bool isValid(int x, int y, int i);

int main()
{
	for (int i{ 0 }; i < 9; i++)
	{
		for (int j{ 0 }; j < 9; j++)
		{
			cin >> sudoku[i][j];
		}
	}

	f(0, 0);
}

void f(int x, int y)
{
	if (x == 9)
	{
		for (int i{ 0 }; i < 9; i++)
		{
			for (int j{ 0 }; j < 9; j++)
			{
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	if (sudoku[x][y] == 0)
	{
		for (int i{ 1 }; i <= 9; i++)
		{
			if (isValid(x, y, i))
			{
				sudoku[x][y] = i;
				if (y == 8) f(x + 1, 0);
				else f(x, y + 1);
				sudoku[x][y] = 0;
			}
		}
	}
	else
	{
		if (y == 8) f(x + 1, 0);
		else f(x, y + 1);
	}
}

bool isValid(int x, int y, int i)
{
	for (int k{ 0 }; k < 9; k++)
	{
		if (sudoku[x][k] == i) return false;
		if (sudoku[k][y] == i) return false;
	}
	for (int p{ x / 3 * 3 }; p < x / 3 * 3 + 3; p++)
	{
		for (int q{ y / 3 * 3 }; q < y / 3 * 3 + 3; q++)
		{
			if (sudoku[p][q] == i) return false;
		}
	}
	return true;
}