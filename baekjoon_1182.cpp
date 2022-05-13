#include <iostream>
#include <vector>
#include <array>
using namespace std;

void bruteforce(int N, int S, int cnt, int loc, int &c, array<int, 20> &arr, vector<int> &partArr);

int main()
{
	int N, S, i, n, c{ 0 };
	array<int, 20> arr;
	vector<int> partArr;
	cin >> N >> S;

	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (i = 0; i < N; i++)
	{
		bruteforce(N, S, i + 1, 0, c, arr, partArr);
	}
	cout << c;
}

void bruteforce(int N, int S, int cnt, int loc, int& c, array<int, 20>& arr, vector<int>& partArr)
{
	int i;
	if (cnt == 0)
	{
		int sum = 0;
		for (i = 0; i < partArr.size(); i++)
		{
			sum += partArr[i];
			cout << partArr[i] << " ";
		}
		cout << endl;
		if (sum == S) c++;
	}
	else if (loc == N) return;

	for (i = loc; i < N; i++)
	{
		partArr.push_back(arr[i]);
		bruteforce(N, S, cnt - 1, i + 1, c, arr, partArr);
		partArr.pop_back();
	}
}