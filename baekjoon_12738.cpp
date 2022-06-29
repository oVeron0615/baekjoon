#include <iostream>
using namespace std;

int len[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A, L{ 1 }; //len[i] : 길이가 i인 배열의 마지막(최댓)값

	cin >> N;
	for (int i{ 1 }; i <= N; i++) len[i] = -1000000000;

	for (int i{ 1 }; i <= N; i++)
	{
		cin >> A; //수를 입력받으며 len[i]를 수정
		int l{ 0 }, r{ L };

		while (true) //이분 탐색 - A보다 큰 수 중 가장 작은 수를 len에서 찾으면 이를 대체
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