#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int C, N;
vector<int> hen;
vector<bool> check;
vector<array<int, 2>> cow;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//�Է�
	cin >> C >> N;
	int h;
	for (int i{ 0 }; i < C; i++)
	{
		cin >> h;
		hen.push_back(h);
		check.push_back(false);
	}
	array<int, 2> c;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> c[1] >> c[0];
		cow.push_back(c);
	}
	sort(hen.begin(), hen.end()); //���� �ð��� ����
	sort(cow.begin(), cow.end()); //���� �ð��� ����

	int ans{ 0 };
	for (int i{ 0 }; i < N; i++)
	{
		int henIndex{ 0 };
		while (true)
		{
			if (henIndex == C) break;

			if (hen[henIndex] <= cow[i][0] && hen[henIndex] >= cow[i][1] && !check[henIndex])
			{
				ans++;
				check[henIndex] = true;
				break;
			}
			else if (hen[henIndex] < cow[i][1] || check[henIndex]) henIndex++;
			else break;
		}
	}
	cout << ans;
}