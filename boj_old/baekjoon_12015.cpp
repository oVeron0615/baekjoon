#include <iostream>
using namespace std;

int len[1000001] = {};

int main()
{
	int N, A, L{ 1 }; //len[i] : ���̰� i�� �迭�� ������ ��

	cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		cin >> A; //���� �Է¹����� len[i]�� ����
		int l{ 0 }, r{ L };

		while (true)
		{
			if (r - l == 1)
			{
				len[r] = A;
				if (r == L) L++;
				break;
			}

			int m;
			if ((l + r) % 2 == 0) m = (l + r) / 2;
			else m = (l + r) / 2 + 1;

			if (A > len[m]) l = m;
			else r = m;
		}
	}

	cout << L - 1;
}