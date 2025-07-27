#include <iostream>
#include <array>
using namespace std;

int main()
{
	long long N, min1{ 50 }, min2{ 100 }, min3{ 150 }, ans{ 0 };
	array<int, 6> dice;

	//입력, 한 면의 최솟값(min1) - 면
	cin >> N;
	if (N == 1)
	{
		int max{ 0 };
		for (int i{ 0 }; i < 6; i++)
		{
			cin >> dice[i];
			ans += dice[i];
			if (max < dice[i]) max = dice[i];
		}
		ans -= max;
		cout << ans;
	}
	else
	{
		for (int i{ 0 }; i < 6; i++)
		{
			cin >> dice[i];
			if (min1 > dice[i]) min1 = dice[i];
		}
		ans += min1 * ((N - 2) * (N - 1) * 4 + (N - 2) * (N - 2));

		//두 면의 합의 최솟값(min2) - 모서리
		for (int i{ 0 }; i < 6; i++)
		{
			for (int j{ i + 1 }; j < 6; j++)
			{
				if (i + j != 5)
				{
					if (min2 > dice[i] + dice[j]) min2 = dice[i] + dice[j];
				}
			}
		}
		ans += min2 * ((N - 2) * 4 + (N - 1) * 4);

		//세 면의 합의 최솟값(min3) - 꼭짓점
		for (int i{ 0 }; i < 6; i++)
		{
			for (int j{ i + 1 }; j < 6; j++)
			{
				for (int k{ j + 1 }; k < 6; k++)
				{
					if (i + j != 5 && j + k != 5 && k + i != 5)
					{
						if (min3 > dice[i] + dice[j] + dice[k]) min3 = dice[i] + dice[j] + dice[k];
					}
				}
			}
		}
		ans += min3 * 4;

		cout << ans;
	}
}