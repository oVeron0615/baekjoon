#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> A, B, sumA(1, 0), sumB(1, 0);

int main()
{
	int N, C; cin >> N >> C;

	for (int i{ 0 }; i < N; i++)
	{
		int w; cin >> w;
		if (i < N / 2) A.push_back(w);
		else B.push_back(w);
	}

	for (int i{ 0 }; i < A.size(); i++)
	{
		int s = sumA.size();
		for (int j{ 0 }; j < s; j++)
		{
			sumA.push_back(A[i] + sumA[j]);
		}
	}
	for (int i{ 0 }; i < B.size(); i++)
	{
		int s = sumB.size();
		for (int j{ 0 }; j < s; j++)
		{
			sumB.push_back(B[i] + sumB[j]);
		}
	}
	sort(sumB.begin(), sumB.end());

	long long cnt{ 0 };
	for (int i{ 0 }; i < sumA.size(); i++)
	{
		long long k = C - sumA[i];
		
		if (k < sumB[0]) continue;
		else if (k >= sumB[sumB.size() - 1]) cnt += sumB.size();
		else
		{
			int l = 0, r = sumB.size();
			while (r - l != 1)
			{
				int m{ (l + r) / 2 };
				if (k >= sumB[m]) l = m;
				else r = m;
			}
			cnt += l + 1;
		}
	}
	cout << cnt;
}