#include <iostream>
#include <array>
using namespace std;

int main()
{
	int N, S;
	array<int, 20> arr;
	cin >> N >> S;

	for (int i{ 0 }; i < N; i++) cin >> arr[i];

	int ans{ 0 };
	for (int i{ 1 }; i < (1 << N); i++)
	{
		int sum{ 0 };
		for (int j{ 0 }; j < N; j++)
		{
			if (i & (1 << j)) sum += arr[j];
		}
		if (sum == S) ans++;
	}

	cout << ans;
}

//��Ʈ����ŷ : ��Ʈ ������ �̿��� �迭 ǥ���
//line14 : 1���� 2�� N�� - 1���� ����(00001 ~ 11111)
//line19 : 1�� j��ŭ �о �� �ڸ��� 1�� ������ 1�� ����, �ƴϸ� 0 ����
/*
i : 0 0 1 1 0
j : 0 0 1 0 0
��: 0 0 1 0 0 - 0�ƴϹǷ� ��
�Ȱ��� 1�̸� �ش� �ε����� ���ϴ� ���Ұ� �����Ѵٴ� ��
*/