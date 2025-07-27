#include <iostream>
#include <vector>
using namespace std;

int A[1000];
vector<int> LIS[1000];

int main()
{
	int ans{ 0 }, ind;

	int N; cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> A[i];
		int idx{ 0 }, mx{ 0 };
		for (int j{ 0 }; j < i; j++)
		{
			if (mx < LIS[j].size() && A[i] > A[j])
			{
				mx = LIS[j].size();
				idx = j;
			}
		}
		if (mx != 0) LIS[i] = LIS[idx];
		LIS[i].push_back(A[i]);

		if (ans < LIS[i].size())
		{
			ans = LIS[i].size();
			ind = i;
		}
	}

	cout << ans << "\n";
	for (int i{ 0 }; i < LIS[ind].size(); i++) cout << LIS[ind][i] << " ";
}