#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<array<int, 2>> classes;
	array<int, 2> c;

	//입력, 회의 시작 순으로 오름차순 정렬
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> c[0] >> c[1];
		classes.push_back(c);
	}
	sort(classes.begin(), classes.end());

	int ans{ 0 };
	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(classes[0][1]); //첫 수업 끝나는 시간 push
	ans++;
	for (int i{ 1 }; i < N; i++)
	{
		pq.push(classes[i][1]); //수업 끝나는 시간 push
		ans++;
		if (classes[i][0] >= pq.top()) //수업 시작 시간이 가장 빨리 끝나는 시간보다 크거나 같으면
		{
			pq.pop(); //그 시간은 pop
			ans--;
		}
	}
	cout << ans;
}