#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, cnt[32001];
vector<int> pro[32001];
bool vis[32001];
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
	cin >> N >> M;
	for (int i{ 0 }; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		pro[A].push_back(B);
		cnt[B]++;
	}
	for (int i{ 1 }; i <= N; i++)
	{
		if (!cnt[i]) pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";

		for (int i : pro[cur])
		{
			cnt[i]--;
			if (!cnt[i]) pq.push(i);
		}
	}
}