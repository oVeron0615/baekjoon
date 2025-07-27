#include <iostream>
#include <vector>
using namespace std;

bool chess[10][10];
vector<pair<int, int>> bishop1, bishop2;
int mx1{ 0 }, mx2{ 0 }, n;

void f(int, int);

int main()
{
	cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		for (int j{ 0 }; j < n; j++)
		{
			cin >> chess[i][j];
		}
	}

	for (int i{ 0 }; i <= n * 2 - 2; i++)
	{
		for (int j{ 0 }; j <= i; j++)
		{
			if (chess[j][i - j])
			{
				if (i % 2 == 0)
				{
					bishop1.push_back({ j, i - j });
					f(i + 2, 1);
					bishop1.pop_back();
				}
				else
				{
					bishop2.push_back({ j, i - j });
					f(i + 2, 1);
					bishop2.pop_back();
				}
			}
		}
	}
	cout << mx1 + mx2;
}

void f(int x, int cnt)
{
	for (int i{ x }; i <= n * 2 - 2; i += 2)
	{
		for (int j{ 0 }; j <= i; j++)
		{
			if (j >= n || i - j >= n) continue;
			if (chess[j][i - j])
			{
				bool check{};
				if (x % 2 == 0)
				{
					for (int k{ 0 }; k < bishop1.size(); k++)
					{
						auto [p, q] = bishop1[k];
						if (j * 2 - i == p - q)
						{
							check = true;
							break;
						}
					}
					if (!check)
					{
						bishop1.push_back({ j, i - j });
						f(i + 2, cnt + 1);
						bishop1.pop_back();
					}
				}
				else
				{
					for (int k{ 0 }; k < bishop2.size(); k++)
					{
						auto [p, q] = bishop2[k];
						if (j * 2 - i == p - q)
						{
							check = true;
							break;
						}
					}
					if (!check)
					{
						bishop2.push_back({ j, i - j });
						f(i + 2, cnt + 1);
						bishop2.pop_back();
					}
				}
			}
		}
	}

	if(x % 2 == 0) mx1 = max(mx1, cnt);
	else mx2 = max(mx2, cnt);
}