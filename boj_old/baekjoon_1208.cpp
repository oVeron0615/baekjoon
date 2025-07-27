#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<long long> setA, setB;
vector<long long> sumA, sumB;
long long Bcount[8000001];

int main()
{
	cin >> N >> S;
	for (int i{ 0 }; i < N; i++)
	{
		int n; cin >> n;
		if (i < N / 2) setA.push_back(n);
		else setB.push_back(n);
	}

	for (int i{ 0 }; i < setA.size(); i++)
	{
		int s = sumA.size();
		for (int j{ 0 }; j < s; j++)
		{
			sumA.push_back(sumA[j] + setA[i]);
		}
		sumA.push_back(setA[i]);
	}
	for (int i{ 0 }; i < setB.size(); i++)
	{
		int s = sumB.size();
		for (int j{ 0 }; j < s; j++)
		{
			sumB.push_back(sumB[j] + setB[i]);
			Bcount[sumB[j] + setB[i] + 4000000]++;
		}
		sumB.push_back(setB[i]);
		Bcount[setB[i] + 4000000]++;
	}
	sort(sumB.begin(), sumB.end());

	long long cnt{ 0 };
	for (int i{ 0 }; i < sumA.size(); i++)
	{
		if (sumA[i] == S) cnt++;

		int l = 0, r = sumB.size();
		while (r - l != 1)
		{
			int m{ (l + r) / 2 };
			if (S - sumA[i] >= sumB[m]) l = m;
			else r = m;
		}
		if (S == sumA[i] + sumB[l]) cnt += Bcount[sumB[l] + 4000000];
	}
	for (int i{ 0 }; i < sumB.size(); i++)
	{
		if (sumB[i] == S) cnt++;
	}
	cout << cnt;
}