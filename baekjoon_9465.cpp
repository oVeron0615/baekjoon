#include <iostream>
#include <array>
using namespace std;

array<array<int, 100000>, 2> sticker;
array<array<bool, 100000>, 2> check{};

void cinSticker(int n);
int max_score(int n, int locX, bool locY);
void check_clear(int n);

int main()
{
	int T;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int i{ 0 }; i < T; i++)
	{
		int n;
		cin >> n;
		cinSticker(n);

		int a{ max_score(n, 0, 0) }, b{ max_score(n, 0, 1) };
		cout << (a > b ? a : b) << "\n";

		check_clear(n);
	}
}

void cinSticker(int n)
{
	for (int i{ 0 }; i < 2; i++)
	{
		for (int j{ 0 }; j < n; j++)
		{
			cin >> sticker[i][j];
		}
	}
}

int max_score(int n, int locX, bool locY)
{
	if (locX >= n) return 0;
	if (check[locY][locX]) return sticker[locY][locX];

	int a{ max_score(n, locX + 1, !locY) };
	int b{ max_score(n, locX + 2, !locY) };
	sticker[locY][locX] += (a > b ? a : b);
	check[locY][locX] = true;
	return sticker[locY][locX];
}

void check_clear(int n)
{
	for (int i{ 0 }; i < 2; i++)
	{
		for (int j{ 0 }; j < n; j++)
		{
			check[i][j] = false;
		}
	}
}