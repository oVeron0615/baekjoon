#include <iostream>
#include <array>
#include <vector>
using namespace std;

array<bool, 9> arr{};
vector<int> v;

void DFS(int N, int M);

int main()
{
	int N, M;
	cin >> N >> M;

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

	for (i = 1; i <= N; i++)
	{
		if (!arr[i])
		{
			arr[i] = true;
			v.push_back(i);
			DFS(N, M - 1);
			arr[i] = false;
			v.pop_back();
		}
	}
}
