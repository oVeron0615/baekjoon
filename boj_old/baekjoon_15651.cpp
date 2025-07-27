#include <iostream>
#include <vector>
using namespace std;

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
		v.push_back(i);
		DFS(N, M - 1);
		v.pop_back();
	}
}
