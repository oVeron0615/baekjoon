#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

array<bool, 8> arr{};
vector<int> v, number;

void DFS(int N, int M);

int main()
{
	int N, M, i, n;
	cin >> N >> M;

	for (i = 1; i <= N; i++)
	{
		cin >> n;
		number.push_back(n);
	}
	sort(number.begin(), number.end());

	DFS(N, M);
}

void DFS(int N, int M)
{
	int i;
	if (M == 0)
	{
		for (i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (i = 0; i < N; i++)
	{
		if (!arr[i])
		{
			arr[i] = true;
			v.push_back(number[i]);
			DFS(N, M - 1);
			arr[i] = false;
			v.pop_back();
		}
	}
}