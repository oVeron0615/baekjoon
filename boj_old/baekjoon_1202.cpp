#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	vector<array<int, 2>> gem;
	vector<int> bag;
	array<int, 2> gemInform;
	int b;

	//입력
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> gemInform[0] >> gemInform[1];
		gem.push_back(gemInform);
	}
	for (int i{ 0 }; i < K; i++)
	{
		cin >> b;
		bag.push_back(b);
	}
	sort(gem.begin(), gem.end()); //무게 순으로 보석 정렬
	sort(bag.begin(), bag.end()); //크기 순으로 가방 정렬

	priority_queue<array<int, 2>, vector<array<int, 2>>> pq;
	int gemIndex{ 0 };
	long long ans{ 0 };
	for (int i{ 0 }; i < K; i++)
	{
		//우선순위 큐에 보석의 정보를 가치가 큰 순대로, 가방보다 작은 무게까지 저장
		while (gemIndex < N && gem[gemIndex][0] <= bag[i])
		{
			array<int, 2> temp;
			temp[0] = gem[gemIndex][1];
			temp[1] = gem[gemIndex][0];
			pq.push(temp);
			gemIndex++;
		}
		if (!pq.empty())
		{
			ans += pq.top()[0];
			pq.pop();
		}
	}
	cout << ans;
}