#include <iostream>
#include <array>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int N, M, ans{ INT_MAX };
vector<array<int, 2>> chicken, house;
vector<int> chilen;

void f(int k);

int main()
{
	//입력 - 1은 house, 2는 chicken에 저장
	cin >> N >> M;
	int building;
	array<int, 2> spot;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> building;
			if (building == 1)
			{
				spot[0] = i; spot[1] = j;
				house.push_back(spot);
			}
			if (building == 2)
			{
				spot[0] = i; spot[1] = j;
				chicken.push_back(spot);
			}
		}
	}

	//치킨집 고르기 - 비트마스킹
	for (int i{ 0 }; i < (1 << chicken.size()); i++)
	{
		int count{ 0 };
		for (int j{ 0 }; j < chicken.size(); j++)
		{
			if (i & (1 << j)) count++;
		}

		if (count == M)
		{
			for (int j{ 0 }; j < house.size(); j++) chilen.push_back(INT_MAX);
			f(i);
			chilen.clear();
		}
	}

	cout << ans;
}

//각 집에 대하여 치킨 거리를 구함
void f(int k)
{
	for (int i{ 0 }; i < chicken.size(); i++)
	{
		if (k & (1 << i))
		{
			for (int j{ 0 }; j < chilen.size(); j++)
			{
				chilen[j] = min(chilen[j],
					abs(house[j][0] - chicken[i][0]) + abs(house[j][1] - chicken[i][1]));
			}
		}
	}

	int sum{ 0 };
	for (int i : chilen) sum += i;
	ans = min(ans, sum);
}