#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> order;
vector<int> v;

int hanoinumber(int K);
void hanoi(int K, int start, int end);

int main()
{
	int K;

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	cin >> K;
	cout << hanoinumber(K) << "\n";

	hanoi(K, 1, 3);

	for (int i{ 0 }; i < order.size(); i++)
	{
		cout << order[i][0] << " " << order[i][1] << "\n";
	}
}

int hanoinumber(int K)
{
	if (K == 1) return 1;
	return hanoinumber(K - 1) * 2 + 1;
}

void hanoi(int K, int start, int end)
{
	if (K == 1)
	{
		v.push_back(start), v.push_back(end);
		order.push_back(v);
		v.clear();
		return;
	}

	int mid = 6 - start - end;

	hanoi(K - 1, start, mid);

	v.push_back(start), v.push_back(end);
	order.push_back(v);
	v.clear();

	hanoi(K - 1, mid, end);
}