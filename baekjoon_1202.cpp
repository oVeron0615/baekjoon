#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	vector<array<int, 2>> gem;
	vector<int> bag;
	array<int, 2> gemInform;
	int b;

	//�Է�
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> gemInform[0] >> gemInform[1];
		gem.push_back(gemInform);
	}
	for (int i{ 0 }; i < K; i++)
	{
		cin >> b;
		bag.push_back(b);
	}
	sort(gem.begin(), gem.end()); //���� ������ ���� ����
	sort(bag.begin(), bag.end()); //ũ�� ������ ���� ����

	priority_queue<array<int, 2>, vector<array<int, 2>>> pq;
	int gemIndex{ 0 };
	long long ans{ 0 };
	for (int i{ 0 }; i < K; i++)
	{
		//�켱���� ť�� ������ ������ ��ġ�� ū �����, ���溸�� ���� ���Ա��� ����
		while (gemIndex < N && gem[gemIndex][0] <= bag[i])
		{
			array<int, 2> temp;
			temp[0] = gem[gemIndex][1];
			temp[1] = gem[gemIndex][0];
			pq.push(temp);
			gemIndex++;
		}
		if (!pq.empty())
		{
			ans += pq.top()[0];
			pq.pop();
		}
	}
	cout << ans;
}