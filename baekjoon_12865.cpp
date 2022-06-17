#include <iostream>
#include <array>
using namespace std;

array<array<int, 2>, 100> bag;
array<array<int, 2>, 100001> weight_value{}; //���� �� ��ġ

void dynamic_programming(int N, int K, int loc, int lastweight);

int main()
{
	int N, K;

	//�Է�
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> bag[i][0] >> bag[i][1];
	}

	//���� ���԰� ���� ������, ���԰� ������ ��ġ�� ū ������ ����
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ i };; j--)
		{
			if (j == 0) break;
			else
			{
				if (bag[j][0] < bag[j - 1][0]
					|| (bag[j][0] == bag[j - 1][0] && bag[j][1] > bag[j - 1][1]))
				{
					int tempW{ bag[j][0] }, tempV{ bag[j][1] };
					bag[j][0] = bag[j - 1][0];
					bag[j][1] = bag[j - 1][1];
					bag[j - 1][0] = tempW;
					bag[j - 1][1] = tempV;
				}
				else break;
			}
		}
	}

	dynamic_programming(N, K, 0, 0);

	//�ִ� ã��
	int max{ 0 };
	for (int i{ 1 }; i <= K; i++)
	{
		if (max < weight_value[i][0]) max = weight_value[i][0];
	}
	cout << max;
}

/*
���� ������ ���Կ� �ش��ϴ� ��ġ�� ���� ������ ���Կ� �ش��ϴ� ��ġ�� ����
�� ������ �տ� �ش��ϴ� ��ġ���� ũ�� ������ ������ ������ ���� ��ü
�� ������ ���� K�� ������ ����
*/
void dynamic_programming(int N, int K, int loc, int lastweight)
{
	for (int i{ loc }; i < N; i++)
	{
		if (lastweight + bag[i][0] > K) return;
		if ((weight_value[lastweight][0] + bag[i][1] > weight_value[lastweight + bag[i][0]][0])
			|| (weight_value[lastweight][0] + bag[i][1] == weight_value[lastweight + bag[i][0]][0]
				&& (weight_value[lastweight + bag[i][0]][1] > i || weight_value[lastweight + bag[i][0]][1] == 0)))
		{
			weight_value[lastweight + bag[i][0]][0] =
				weight_value[lastweight][0] + bag[i][1];
			weight_value[lastweight + bag[i][0]][1] = i;
			dynamic_programming(N, K, i + 1, lastweight + bag[i][0]);
		}
	}
}