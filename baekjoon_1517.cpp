#include <iostream>
#include <array>
using namespace std;

array<int, 500000> bubble;
array<int, 500000> temp;
long long Swap{ 0 };

void merge_sort(int left, int right);
void merge(int left, int right);

int main()
{
	int N, number;

	cin >> N;
	for (int i{ 0 }; i < N; i++) cin >> bubble[i];

	merge_sort(0, N - 1); //병합 정렬을 이용

	cout << Swap;
}

void merge_sort(int left, int right) //단순한 병합 정렬 알고리즘
{
	if (left == right) return;

	int mid = (left + right) / 2;

	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	merge(left, right);
}

void merge(int left, int right)
{
	int L, M, mid, k;
	L = left;
	mid = (left + right) / 2;
	M = mid + 1;
	k = left;

	while (L <= mid && M <= right)
	{
		if (bubble[L] <= bubble[M])
		{
			temp[k] = bubble[L];
			L++; k++;
		}
		else
		{
			temp[k] = bubble[M];
			M++; k++;
			Swap += mid + 1 - L; //여기서 swap을 연산해주면 됨
		}
	}

	if (M > right)
	{
		for (int i{ L }; i <= mid; i++)
		{
			temp[k] = bubble[i];
			k++;
		}
	}
	else
	{
		for (int i{ M }; i <= right; i++)
		{
			temp[k] = bubble[i];
			k++;
		}
	}

	for (int i{ left }; i <= right; i++) bubble[i] = temp[i];
}