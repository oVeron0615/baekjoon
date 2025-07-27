#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> house;
int N, C;

int main()
{
	//�Է�, ����
	cin >> N >> C;
	int spot;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> spot;
		house.push_back(spot);
	}
	sort(house.begin(), house.end());

	//�� ������ ������ �Ÿ��� �̺� Ž������ Ž��
	int l{ 1 }, r{ house[house.size() - 1] - house[0] + 1 };
	while (true)
	{
		if (r - l == 1)
		{
			cout << l;
			break;
		}

		int router{ 1 }, houseLoc{ house[0] };
		int mid{ (l + r) / 2 };

		//������ ������ �Ÿ��� �ּ� mid�� �� ������ ���� ����
		for (int i{ 1 }; i < N; i++)
		{
			if (house[i] - houseLoc >= mid)
			{
				router++;
				houseLoc = house[i];
			}
		}

		if (router >= C) l = mid;
		else r = mid;
	}
}