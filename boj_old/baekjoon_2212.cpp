#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	vector<int> sensor;

	cin >> N >> K;
	for (int i{ 0 }; i < N; i++)
	{
		int s;
		cin >> s;
		sensor.push_back(s);
	}
	sort(sensor.begin(), sensor.end());

	priority_queue<int, vector<int>> pq;
	int ans{ 0 };
	for (int i{ 1 }; i < N; i++) pq.push(sensor[i] - sensor[i - 1]);
	for (int i{ 1 }; i < N; i++)
	{
		if (i < K) pq.pop();
		else
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}