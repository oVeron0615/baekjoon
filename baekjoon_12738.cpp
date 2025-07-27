#include <iostream>
using namespace std;

int len[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A, L{ 1 }; //len[i] : ���̰� i�� �迭�� ������(�ִ�)��

	cin >> N;
	for (int i{ 1 }; i <= N; i++) len[i] = -1000000000;

	for (int i{ 1 }; i <= N; i++)
	{
		cin >> A; //���� �Է¹����� len[i]�� ����
		int l{ 0 }, r{ L };

		while (true) //�̺� Ž�� - A���� ū �� �� ���� ���� ���� len���� ã���� �̸� ��ü
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