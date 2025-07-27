#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, ans{ 0 };
	vector<array<int, 2>> homework;
	array<bool, 1001> check{};

	//과제 입력, 마감일 오름차순 정렬
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		array<int, 2> wd;
		cin >> wd[1] >> wd[0];
		homework.push_back(wd);
	}
	sort(homework.begin(), homework.end(), greater<>());

	for (int i{ 0 }; i < N; i++)
	{
		cout << homework[i][0] << " " << homework[i][1] << endl;
		int index{ homework[i][1] };
		while (true)
		{
			if (index == 0) break;

			if (check[index]) index--;
			else
			{
				check[index] = true;
				ans += homework[i][0];
				break;
			}
		}
	}

	cout << ans;
}