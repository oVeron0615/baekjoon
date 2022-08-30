#include <iostream>
#include <vector>
using namespace std;

int movement[10], horse[10];
int board[6][20] =
{
	{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38},
	{10, 13, 16, 19},
	{20, 22, 24},
	{30, 28, 27, 26},
	{25, 30, 35},
	{40}
};
int ans{ 0 };

void f(int);
void game();

int main()
{
	for (int i{ 0 }; i < 10; i++) cin >> movement[i];
	f(0);
	cout << ans;
}

void f(int n)
{
	if (n == 10)
	{
		game();
		return;
	}
	for (int i{ 0 }; i < 4; i++)
	{
		horse[n] = i;
		f(n + 1);
	}
}

void game()
{
	int loc[4][2] = {};
	int sum{ 0 };
	for (int i{ 0 }; i < 10; i++)
	{
		loc[horse[i]][1] += movement[i];

		if (loc[horse[i]][0] == 0)
		{
			if (loc[horse[i]][1] == 5)
			{
				loc[horse[i]][0] = 1;
				loc[horse[i]][1] = 0;
			}
			else if (loc[horse[i]][1] == 10)
			{
				loc[horse[i]][0] = 2;
				loc[horse[i]][1] = 0;
			}
			else if (loc[horse[i]][1] == 15)
			{
				loc[horse[i]][0] = 3;
				loc[horse[i]][1] = 0;
			}
			else if (loc[horse[i]][1] == 20)
			{
				loc[horse[i]][0] = 5;
				loc[horse[i]][1] = 0;
			}
			else if (loc[horse[i]][1] > 20) continue;
		}
		if (loc[horse[i]][0] == 1)
		{
			if (loc[horse[i]][1] > 3)
			{
				loc[horse[i]][0] = 4;
				loc[horse[i]][1] -= 4;
			}
		}
		if (loc[horse[i]][0] == 2)
		{
			if (loc[horse[i]][1] > 2)
			{
				loc[horse[i]][0] = 4;
				loc[horse[i]][1] -= 3;
			}
		}
		if (loc[horse[i]][0] == 3)
		{
			if (loc[horse[i]][1] > 3)
			{
				loc[horse[i]][0] = 4;
				loc[horse[i]][1] -= 4;
			}
		}
		if (loc[horse[i]][0] == 4)
		{
			if (loc[horse[i]][1] > 2)
			{
				loc[horse[i]][0] = 5;
				loc[horse[i]][1] -= 3;
			}
		}
		if (loc[horse[i]][0] == 5)
		{
			if (loc[horse[i]][1] > 1) continue;
		}

		for (int j{ 0 }; j < 4; j++)
		{
			if (j == horse[i]) continue;
			if (loc[j][0] == loc[horse[i]][0] && loc[j][1] == loc[horse[i]][1]) return;
		}
		sum += board[loc[horse[i]][0]][loc[horse[i]][1]];
	}

	ans = max(ans, sum);
}