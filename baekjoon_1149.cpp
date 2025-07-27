#include <iostream>
#include <array>
using namespace std;

//0:»¡ 1:ÃÊ 2:ÆÄ
array<array<int, 3>, 1000> house_color;
array<array<bool, 3>, 1000> cost_check{};

int min_cost(int N, int loc, int color);

int main()
{
	int N;

	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < 3; j++)
		{
			cin >> house_color[i][j];
		}
	}

	cout << min_cost(N, 0, 0);
}

int min_cost(int N, int loc, int color)
{
	if (loc == N) return 0;
	if (loc == 0)
	{
		int r{ min_cost(N, 1, 0) + house_color[0][0] };
		int g{ min_cost(N, 1, 1) + house_color[0][1] };
		int b{ min_cost(N, 1, 2) + house_color[0][2] };

		int min;
		min = r < g ? r : g;
		min = min < b ? min : b;
		return min;
	}

	if (color == 0)
	{
		if(!cost_check[loc][1]) house_color[loc][1] += min_cost(N, loc + 1, 1);
		if(!cost_check[loc][2]) house_color[loc][2] += min_cost(N, loc + 1, 2);
		cost_check[loc][1] = true;
		cost_check[loc][2] = true;
		return house_color[loc][1] < house_color[loc][2]
			? house_color[loc][1] : house_color[loc][2];
	}
	else if (color == 1)
	{
		if (!cost_check[loc][0]) house_color[loc][0] += min_cost(N, loc + 1, 0);
		if (!cost_check[loc][2]) house_color[loc][2] += min_cost(N, loc + 1, 2);
		cost_check[loc][0] = true;
		cost_check[loc][2] = true;
		return house_color[loc][0] < house_color[loc][2]
			? house_color[loc][0] : house_color[loc][2];
	}
	else if (color == 2)
	{
		if (!cost_check[loc][0]) house_color[loc][0] += min_cost(N, loc + 1, 0);
		if (!cost_check[loc][1]) house_color[loc][1] += min_cost(N, loc + 1, 1);
		cost_check[loc][0] = true;
		cost_check[loc][1] = true;
		return house_color[loc][0] < house_color[loc][1] 
			? house_color[loc][0] : house_color[loc][1];
	}
}