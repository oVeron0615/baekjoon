#include <iostream>
using namespace std;

int len[1000001] = {};

int main()
{
	int N, A, L{ 1 }; //len[i] : 길이가 i인 배열의 마지막 값

	cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		cin >> A; //수를 입력받으며 len[i]를 수정
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